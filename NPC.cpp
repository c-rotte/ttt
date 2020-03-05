#include "NPC.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void NPC::turn(Board* board) {

	lastBranchCount = 0;

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	minimax(board, 0, true, INT_MIN, INT_MAX);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	cout << " >> [Ai " << getSign() << "] chose tile ( " << nextX << "," << nextY << " ) after choosing between " << lastBranchCount
		<< " possible outcomes (" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " microseconds)." << endl;

	board->move(getSign(), nextX, nextY);

}

// Minimax Algortihm with alpha beta pruning
int NPC::minimax(Board* currBoard, int depth, bool isMaxPlayer, int alpha, int beta) {

	if (currBoard->hasWon(getSign())) {
		lastBranchCount++;
		return 1;
	}
	if (currBoard->hasWon(otherSign)) {
		lastBranchCount++;
		return -1;
	}
	if (currBoard->tie()) {
		lastBranchCount++;
		return 0;
	}

	if (isMaxPlayer) {

		int bestVal = INT_MIN;

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (currBoard->validMove(x, y)) {
					Board* copyBoard = currBoard->copy();
					copyBoard->move(getSign(), x, y);
					int value = minimax(copyBoard, depth + 1, false, alpha, beta);
					delete copyBoard;

					// Set next coordinates if it's the best approach
					if (value > bestVal && depth == 0) {
						nextX = x;
						nextY = y;
					}

					bestVal = value > bestVal ? value : bestVal;
					alpha = alpha > bestVal ? alpha : bestVal;
					if (beta <= alpha) {
						break;
					}
				}
			}
		}

		return bestVal;

	} else {

		int bestVal = INT_MAX;

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (currBoard->validMove(x, y)) {
					Board* copyBoard = currBoard->copy();
					copyBoard->move(otherSign, x, y);
					int value = minimax(copyBoard, depth + 1, true, alpha, beta);
					delete copyBoard;

					bestVal = value < bestVal ? value : bestVal;
					beta = beta < bestVal ? beta : bestVal;
					if (beta <= alpha) {
						break;
					}
				}
			}
		}

		return bestVal;

	}

}

