/*
 * Viewer.cpp
 *
 *  Created on: Oct 28, 2012
 *      Author: mike and alice
 */

#include "Viewer.hpp"
#include "Canvas.hpp"

// ------------------------------------------------------------------
Viewer::Viewer(int nr, int nc, CanView& model) :
    numRows(nr), numCols(nc), sqInBox(3), sqWid(9), sqHig(4),
    colSpan( sqWid + 1), rowSpan(sqHig + 1), width(colSpan * numCols + 1),
    height( rowSpan * numRows + 1), cv(new Canvas(height, width)),
    model(model)
{
    drawGrid();
}

// ------------------------------------------------------------------
Viewer::~Viewer() {
    delete cv;
}

// ------------------------------------------------------------------
// Draw and print the board
// Note: The board uses 1-based indexing, but we use 0-based indexing for the pixels
void Viewer::show(ostream& out) {
    for (int row = 1; row <= numRows; ++row)
        for (int col = 1; col <= numCols; ++col) {
            int sr0 = (row-1) * rowSpan + 1;	// disp coords of UL corner
            int sc0 = (col-1) * colSpan + 1;
            string ps = model.getPossibilityString(row, col);
            for (int k = 0; k < 9; ++k) {
                cv->setPixel(sr0, sc0 + k, ps[k]);
            }
            cv->setPixel(sr0 + 2, sc0 + 4, model.getMarkChar(row, col));
        }
    cv->show(out);
}

// ------------------------------------------------------------------
// Coordinates:
// row and column are square coordinates.
// sr and sc are display coordinates
void Viewer::drawGrid() {
    GridChar gc;
    GridChar::LineType rowType;
    GridChar::LineType colType;

    for (int sr = 0; sr < height; ++sr) {
        // Classify row type
        if (topEdge(sr))
            rowType = GridChar::edge1;
        else if (botEdge(sr))
            rowType = GridChar::edge2;
        else if (majorRow(sr))
            rowType = GridChar::major;
        else if (minorRow(sr))
            rowType = GridChar::minor;
        else
            rowType = GridChar::none;

        for (int sc = 0; sc < width; ++sc) { // Classify col type
            if (leftEdge(sc))
                colType = GridChar::edge1;
            else if (rightEdge(sc))
                colType = GridChar::edge2;
            else if (majorCol(sc))
                colType = GridChar::major;
            else if (minorCol(sc))
                colType = GridChar::minor;
            else
                colType = GridChar::none;

            cv->setPixel(sr, sc, gc.boxGlyph(rowType, colType));
        }
    }
}

