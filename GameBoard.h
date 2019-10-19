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
		int numInLineX(int x, int y, int dir);
		int numInLineY(int x, int y, int dir);
		
	public:
		GameBoard();
		~GameBoard();
		void addShip(Ship *newShip);
		std::string fire(int x, int y);
		int** getBoard();
		int** getOppBoard();
		bool gameOver();
		int canFindPath(int x, int y, int shipLength);
		bool isOccupied(int x, int y);
		void updateOppBoard(int x, int y, std::string outcome);
		void updateMyBoard(int x, int y, std::string outcome);
		void printBoard();
		void printOppBoard();
		GameBoard& operator=(const GameBoard &a);
};
#endif
