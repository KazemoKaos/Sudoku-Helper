/*
 * Canvas.hpp
 *
 *  Created on: Oct 27, 2012
 *      Author: mike and alice
 */

#pragma once

#include "MixedChar.hpp"
#include "GridChar.hpp"

// Create a character drawing canvas for producing pseudo-graphical output

class Canvas {
private:

	const int height;
	const int width;
	const GridChar gc;

	MixedChar* pixel;

	MixedChar& sub(int sr, int sc) {
		return pixel[sr * width + sc];
	}
	const MixedChar& sub_const(int sr, int sc) const {
		return pixel[sr * width + sc];
	}

public:
	Canvas(int nr, int nc);
	~Canvas();

	void setPixel(int sr, int sc, MixedChar c) {
		sub(sr, sc) = c;
	}

	void show(ostream& out) const;

};
