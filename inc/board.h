
#ifndef BOARD_H
#define BOARD_H
#include <string>
class Board {

	public:
    Board();
    void setShip(int row,int col);
    bool isHit();
    bool isSunk();
    bool miss();
		~Board();
	private:
		const rowSize = 8;
		const colSize = 8;

};

#endif //board.h
