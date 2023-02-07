/*
 * Viewer.hpp
 *
 *  Created on: Oct 28, 2012
 *      Author: mike and alice
 */
#pragma once

#include <iostream>
#include <string>
#include "CanView.hpp"
using namespace std;

// Interface
class Canvas; 		   // forward
class Viewer {
private:
	const int numRows; // number of Sudoku squares per row
	const int numCols; // number of Sudoku squares per column
	const int sqInBox; // box dimension (in squares)

	const int sqWid;   // width of square (in chars), excluding borders
	const int sqHig;   // height of square (in lines), excluding borders

	const int colSpan; // number of chars from one vertical grid line to next
	const int rowSpan; // number of lines from one horizontal grid line to next

	const int width;   // width of row (in chars), including borders
	const int height;  // height of board (in lines), including borders

	Canvas* cv;
	CanView& model;

	void drawGrid();
	bool topEdge(int sr)  const { return sr==0; }
	bool botEdge(int sr)  const { return sr==height-1; }
 	bool majorRow(int sr)  const { return sr%(rowSpan*sqInBox) == 0; }
	bool minorRow(int sr)  const { return sr%rowSpan == 0; }

	bool leftEdge(int sc)  const { return sc==0; }
	bool rightEdge(int sc) const { return sc==width-1; }
 	bool majorCol(int sc)  const { return sc%(colSpan*sqInBox) == 0; }
	bool minorCol(int sc)  const { return sc%colSpan == 0; }

public:
	Viewer(int nr, int nc, CanView& m);
	virtual ~Viewer();
	void show(ostream& out);
};
