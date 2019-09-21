
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "cell.h"
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
		int m_row;
		int m_col;
		cell m_board[rowSize][colSize];
		cell ***m_board = nullptr;//[rowSize][colSize];

};

#endif //board.h
