#pragma once

#include <iostream>
#include <cstdlib>

#include "GameBoard.h"
#include "Game.h"

using namespace std;

class AIOpponent{

private:
	int numShips;
	GameBoard AIBoard;
		

public:
	AIOpponent(GameBoard AIBoard);

	int getNumShips();

	void easy();

	void medium();

	void hard();

};




