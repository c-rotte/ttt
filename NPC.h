#pragma once
#include "Player.h"

class NPC : public Player {

private:

	int lastBranchCount = 0;
	int nextX = -1, nextY = -1;
	char otherSign;

	int minimax(Board* currBoard, int depth, bool isMaxPlayer, int alpha, int beta);

public: 

	NPC(char sign, char otherSign) : Player(sign) {
		this->otherSign = otherSign;
	}

	void turn(Board* board) override;

};