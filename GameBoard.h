#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
#include <vector>
#include "Ship.h"

class GameBoard{
	private:
		int boardSize;
		int** board;
		int** oppBoard;
		std::vector<Ship*> ships;
		/**
		 * @pre none
		 *		@param x and y coordinates and direction
		 *		@post returns number in line x
		 * 		@return number in line x
		 */
		int numInLineX(int x, int y, int dir);
		/**
		 * @pre none
		 *		@param x and y coordinates and direction
		 *		@postreturns number in line y
		 * 		@return number in line y
		 */
		int numInLineY(int x, int y, int dir);

	public:
		/**
		 * 	@pre none
		 *		@param none
		 *		@post consturctor
		 * 		@return none
		 */
		GameBoard();
		/**
		 * @pre none
		 *		@param none
		 *		@post deconsturctor
		 * 		@return none
		 */
		~GameBoard();
		/**
		 * @pre none
		 *		@param Ships
		 *		@post Adds ships
		 * 		@return none
		 */
		void addShip(Ship *newShip);
		/**
		 * @pre none
		 *		@param x and y coordinates
		 *		@post handles the fire asspect of the game
		 * 		@return hit fire or miss
		 */
		std::string fire(int x, int y);
		/**
		 * @pre none
		 *		@param none
		 *		@post gets the board
		 * 		@return board
		 */
		int** getBoard();
		/**
		 * @pre none
		 *		@param none
		 *		@post gets the opponent board
		 * 		@return opponent board
		 */
		int** getOppBoard();
		/**
		 * @pre one players ships are all sunk
		 *		@param none
		 *		@post game ends
		 * 		@return true or false on if all the ships are sunk
		 */
		bool gameOver();
		/**
		 * @pre none
		 *		@param x and y coordinates and ship's lenght
		 *		@post finds the path
		 * 		@return none
		 */
		int canFindPath(int x, int y, int shipLength);
		/**
		 * @pre none
		 *		@param x and y coordinates
		 *		@post checks to see if a spot is occupied
		 * 		@return true or false on if the ship is occupied
		 */
		bool isOccupied(int x, int y);
		/**
		 * @pre an action has to be done
		 *		@param x and y coordinates and what the outcome of the action
		 *		@post updates the opponent's board
		 * 		@return none
		 */
		void updateOppBoard(int x, int y, std::string outcome);
		/**
		 * @pre an action has to be done
		 *		@param x and y coordinates and what the outcome of the action
		 *		@post updates players board
		 * 		@return none
		 */
		void updateMyBoard(int x, int y, std::string outcome);
		/**
		 * @pre none
		 *		@param none
		 *		@post prints board
		 * 		@return none
		 */
		void printBoard();
		/**
		 * @pre none
		 *		@param none
		 *		@post prints opponent's board
		 * 		@return none
		 */
		void printOppBoard();
		/**
		 * @pre none
		 *		@param none
		 *		@post resets the board
		 * 		@return none
		 */
		void resetBoard();
		/**
		 * @pre none
		 *		@param GameBoard a
		 *		@post = overload
		 * 		@return none
		 */
		GameBoard& operator=(const GameBoard &a);
};
#endif
