/*
 * MixedChar.hpp
 *
 *  Created on: Oct 27, 2012
 *      Author: mike and alice
 */
#pragma once

#include "tools.hpp"

class MixedChar {
private:
	enum Tag_t {
		single, multi
	};
	Tag_t tag;
	union {
		char singleChar;
		const char* multiChar;
	};

public:
    MixedChar() {
        tag = single;
        singleChar = ' ';
    }

    MixedChar(const char* uc) {
        tag = multi;
        multiChar = uc;
    }

    MixedChar(char c) {
        tag = single;
        singleChar = c;
    }

	MixedChar& operator=(const char* uc) {
		tag = multi;
		multiChar = uc;
		return *this;
	}

	MixedChar& operator=(char c) {
		tag = single;
		singleChar = c;
		return *this;
	}

	ostream& print(ostream& out) const;
};

inline
ostream& operator<<(ostream& out, const MixedChar& uc) {
	return uc.print(out);
}
