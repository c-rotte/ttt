#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

Board* Board::copy() {

	return new Board(boardArray);

}

void Board::move(char sign, int x, int y) {

	boardArray[x * 3 + y] = sign;

}

bool Board::validMove(int x, int y) {

	return !(x < 0 || x > 2 || y < 0 || y > 2 || boardArray[x * 3 + y] != '_');

}

bool Board::hasWon(char sign) {

	//Horizontal
	for (int y = 0; y < 3; y++) {
		bool won = true;
		for (int x = 0; x < 3; x++) {
			if (boardArray[x * 3 + y] != sign) {
				won = false;
				break;
			}
		}
		if (won) {
			return true;
		}
	}

	// Vertical
	for (int x = 0; x < 3; x++) {
		bool won = true;
		for (int y = 0; y < 3; y++) {
			if (boardArray[x * 3 + y] != sign) {
				won = false;
				break;
			}
		}
		if (won) {
			return true;
		}
	}

	// Diagonal 1
	bool won = true;
	for (int i = 0; i < 3; i++) {
		if (boardArray[i * 3 + i] != sign) {
			won = false;
			break;
		}
	}
	if (won) {
		return true;
	}

	// Diagonal 2
	won = true;
	for (int x = 0; x < 3; x++) {

		int y = 2 - x;

		if (boardArray[x * 3 + y] != sign) {

			won = false;
			break;
		}
		
	}
	if (won) {
		return true;
	}

	return false;

}

bool Board::tie(void) {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (boardArray[x * 3 + y] == '_') {
				return false;
			}
		}
	}
	
	return true;
}

void Board::printBoard(void) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << " " << boardArray[x * 3 + y];
		}
		cout << endl;
	}
}

Board::~Board() {

	delete[] boardArray;
	boardArray = NULL;

}