#pragma once
#include "Board.h"

class Player {

private:

	char sign;

public:

	Player(char sign) {
		this->sign = sign;
	}

	char getSign(void) {
		return sign;
	}

	virtual void turn(Board* board) = 0;

};