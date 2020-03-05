#pragma once
#include "Player.h"
#include <iostream>

class HumanPlayer : public Player {

private:

	int convert(std::string s);

public: 

	HumanPlayer(char sign) : Player(sign) {}

	void turn(Board* board) override;

};
