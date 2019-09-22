// -*- C++ -*-
/**
* @file   board.cpp
* @date   13 September 2019
* @brief  Provides a gameboard
*/

#include <iostream>

#include "board.h"
#include "cell.h"

Board::Board()
	: Gtk::Grid()
{
	bootstrap_board();
}

Board::~Board() {
	delete m_board;
}

void Board::bootstrap_board() {
	this->m_board = new Cell*[8];
}

void Board::setShip(int row_num,int col_num) {
	// if ((dir == 'u')&&((row_num - (m_size - 1))>=0)) {
	// 	m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
	// 	for(int i = 1;i<=m_size;i++) {
	// 		m_board[--row_num][col_num] -> putShip();
	// 	}
	// }
	// else if ((dir == 'd')&&((row_num + (m_size - 1))<8)) {
	// 	//m_board.setShip(row_num,col_num);
	// 	m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
	// 	for(int i = 1;i<=m_size;i++) {
	// 		m_board[++row_num][col_num] -> putShip();
	// 	}
	// }
	// else if ((dir == 'l')&&((col_num - (m_size - 1))>=0)) {
	// 	m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
	// 	for(int i = 1;i<=m_size;i++) {
	// 		m_board[row_num][--col_num] -> putShip();
	// 	}
	// }
	// else if ((dir == 'r')&&((col_num + (m_size - 1))<8)) {
	// 	m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
	// 	for(int i = 1;i<=m_size;i++) {
	// 		m_board[row_num][--col_num] -> putShip();
	// 	}
	// }
	// else {
	// 	std::cout<<"\nShip is too big to place using the given orientation and position. Try Again!";
	// }
}

void Board::hit(int row, int col) {
	if(m_board == nullptr) {
		// do nothing
	}
	else {
		m_board[row,col]->hit();
	}
}

bool Board::isHit() {

}

bool Board::isSunk() {

}

bool Board::miss() {

}
