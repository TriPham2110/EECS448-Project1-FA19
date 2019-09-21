
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
<<<<<<< HEAD
=======
		cell m_board[rowSize][colSize];
>>>>>>> 4ad276cd905252b5077f66c197048496ee68907d
		cell ***m_board = nullptr;//[rowSize][colSize];


};

#endif //board.h
