#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameBoard.h"
#include "AIOpponent.h"
#include <cstdlib>
#include <time.h>

class Game{
	private:
		GameBoard Player1;
		GameBoard Player2;
		GameBoard AI;
		/*
		 * @ pre user's input on how many ships they want
		 *	@ param GameBoard player 1 and number of ships
		 *	@ post ships are placed onto a board
		 * @ return none
		 */
		void placeShips(GameBoard& player, int numShips);
		/*
		 * @ pre ships are placed for both players
		 *	@ param GameBoard player 1 and 2
		 *	@ post function where two player game is played
		 * @ return none
		 */
		void playGame(GameBoard& Player1, GameBoard& Player2);
		/*
		 * @ pre one player mode is picked
		 *	@ param GameBoard AI and number of ships
		 *	@ post AI ship's are placed
		 * @ return none
		 */
		void placeShipsAI(GameBoard& AI, int numShips);
		/*
		 * @ pre ships are placed for AI and player 1
		 *	@ param GameBoard player 1 and AI and AI difficulty
		 *	@ post function where single player game is played
		 * @ return none
		 */
		void playAI(GameBoard& Player1, GameBoard& AI, int difficulty);
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post gets the column
		 * @ return none
		 */
		int getColumn();
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post gets the row
		 * @ return none
		 */
		int getRow();
		/*
		 * @ pre none
		 *	@ param the option
		 *	@ post points out invalid options
		 * @ return none
		 */
		int restrictIntInput(int option);

	public:
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post constructor
		 * @ return none
		 */
		Game();
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post deconstructor
		 * @ return none
		 */
		~Game();
};
#endif
