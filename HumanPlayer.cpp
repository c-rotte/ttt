#include "HumanPlayer.h"
#include <iostream>
#include <sstream>

using namespace std;

void HumanPlayer::turn(Board* board) {

	cout << endl;
	board->printBoard();

	cout << endl;
	
	int nextX = 0;
	int nextY = 0;

	do {

		cout << " >> [Player " << getSign() << "]: Choose your next tile (x,y): ";
		string answer;
		cin >> answer;
		cin.ignore();

		string x = answer.substr(0, answer.find(","));
		string y = answer.substr(answer.find(",") + 1);
		
		try {
		
			nextX = convert(x);
			nextY = convert(y);

			if (answer.length() == 3 && board->validMove(nextX, nextY)) {
				break;
			}

		} catch (...) {}

		cout << " >> Illegal move! :(" << endl;

	} while (true);

	board->move(getSign(), nextX, nextY);

	cout << endl;
	board->printBoard();

	cout << endl;

}

int HumanPlayer::convert(std::string s) {
	istringstream iss(s);
	int number;
	iss >> number;
	if (iss.fail()) {
		return -1;
	}
	return number;
}
