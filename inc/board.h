
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Ship.h"
#include "Cell.h"
class Board {

	const rowSize = 8;
	const colSize = 8;
	public:
    Board();
    void setShip(int row,int col);
    bool isHit();
    bool isSunk();
    bool miss();
		~Board();
	private:
		cell m_board[rowSize][colSize];


};

#endif //board.h
