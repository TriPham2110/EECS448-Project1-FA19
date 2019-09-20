
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Ship.h"
#include "cell.h"
class Board {

	const rowSize = 8;
	const colSize = 8;
	public:
    Board();
    void setShip(int row,int col,Ship dir, int size);
    bool isHit();
    bool isSunk();
    bool miss();
		~Board();
	private:
		int m_row;
		int m_col;
		cell m_board[rowSize][colSize];


};

#endif //board.h
