#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
#include "NPC.h"

using namespace std;

int main(void) {

	cout << "[Unbeatable Tic Tac Toe.]" << endl
		<< " >> You are playing against an ai that uses Alpha-Beta-Pruning to determine the next best possible move." << endl
		<< " >> Make a move by selecting a valid coordinate, e.g. 1,2 for the bottom-mid tile."
		<< " >> Good luck!" << endl;

	Board board;
	HumanPlayer player1 = HumanPlayer('X');
	NPC player2 = NPC('O', player1.getSign());

	bool player1Turn = true;

	while (!board.hasWon(player1.getSign()) && !board.hasWon(player2.getSign()) && !board.tie()) {

		Player* player;
		if (player1Turn) {
			player = &player1;
		}
		else {
			player = &player2;
		}

		player->turn(&board);

		player1Turn = !player1Turn;

	}

	cout << endl;
	board.printBoard();
	cout << endl;

	if (board.hasWon(player1.getSign())) {
		cout << " >> Player 1 won!" << endl;
	} else if (board.hasWon(player2.getSign())) {
		cout << " >> Player 2 won!" << endl;
	} else if(board.tie()){
		cout << " >> It's a tie!" << endl;
	}

	cin.sync();
	cin.get();

	return 0;

}

