#pragma once
#include <iostream>
#include <vector>

class Board {

private:

	char* boardArray;

public:

	Board(void) {

		boardArray = new char[3 * 3];

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				boardArray[x * 3 + y] = '_';
			}
		}

	}

	Board(char* field) {
		
		boardArray = new char[3 * 3];

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				boardArray[x * 3 + y] = field[x * 3 + y];
			}
		}

	}

	Board* copy();

	void move(char sign, int x, int y);

	bool validMove(int x, int y);

	bool hasWon(char sign);

	bool tie(void);

	void printBoard(void);

	~Board();

};
