#pragma once

#include <iostream>
#include <cstdlib>

#include "GameBoard.h"
#include "Game.h"

using namespace std;

class AIOpponent{

private:

	GameBoard AIBoard;
	int mediumTurnFlag;
	int xRandomValue,yRandomValue;
		

public:
	AIOpponent(GameBoard& AIBoardPass);

	void easyTurn();

	void mediumTurn();

	void hardTurn();

};




