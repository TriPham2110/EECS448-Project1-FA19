#pragma once

#include <iostream>
#include <cstdlib>
#include "GameBoard.h"
#include "Game.h"

class AIOpponent{
	private:

		GameBoard AIBoard;
		GameBoard Player;
		int mediumTurnFlag;
		int xRandomValue,yRandomValue;

	public:
		/*
	     * @ pre none
	     *	@ param GameBoard player 1 and AI
	     *	@ post constructor
	     * @ return none
	     */
		AIOpponent(GameBoard& Player1, GameBoard& AIBoardPass);
		/*
	     * @ pre none
	     *	@ param none
	     *	@ post AI's easy difficulty
	     * @ return none
	     */
		void easyTurn();
		/*
	     * @ pre none
	     *	@ param none
	     *	@ post AI's medium difficulty
	     * @ return none
	     */
		void mediumTurn();
		/*
	     * @ pre none
	     *	@ param none
	     *	@ post AI's hard difficulty
	     * @ return none
	     */
		void hardTurn();
};
