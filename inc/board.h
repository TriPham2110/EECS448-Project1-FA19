
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
    void setShip(int row,int col);
    /**
     * @pre
     * @post
     * @brief
     */
    void hit(int row, int col);

    /**
     * @pre
     * @post
     * @brief
     */
    bool isHit();

    /**
     * @pre
     * @post
     * @brief
     */
    bool isSunk();

    /**
     * @pre
     * @post
     * @brief
     */
    bool miss();
		~Board();
	private:
		cell m_board[rowSize][colSize];


};

#endif //board.h
