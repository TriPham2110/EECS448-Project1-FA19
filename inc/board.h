// -*- C++ -*-
/**
 * @file board.cpp
 * @date 20 September 2019
 * @brief
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "cell.h"

#define ROWS 8
#define COLS 8

#include <gtkmm/grid.h>

class Board : public Gtk::Grid {

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

		Cell m_board[ROWS][COLS];
		Cell ***m_board_ptr = nullptr;//[rowSize][colSize];

};

#endif //board.h
