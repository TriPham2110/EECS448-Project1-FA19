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
	for(int i = 0;i<8;i++)
	{
		m_board[i] = new Cell[8];
	}
}

void Board::setShip(int row_num,int col_num, int size, char direction)
{
	if((direction == 'h')&&((col_num + (size - 1))<8))
	{
		m_board[row_num][col_num].putShip();
		for(int i = 1;i<size;i++)
		{
			m_board[row_num][++col_num].putShip();
		}
	}

	else if ((direction == 'v')&&((row_num + (size - 1))<8))
	{
		m_board[row_num][col_num].putShip();
		for(int i = 1;i<size;i++)
		{
			m_board[++row_num][col_num].putShip();
		}
	}
	else
	{
		std::cout<<"\nShip is too big to place using the given orientation and position. Try Again!\n";
	}
}

void Board::hit(int row, int col) {
	if(m_board == nullptr) {
		// do nothing
	}
	else {
		m_board[row][col].hit();
	}
}

bool Board::isHit(int row, int col) {
	if(m_board[row][col].hasShip())
		{
			return true;
		}
		return false;
}

bool Board::isSunk() {

}

bool Board::miss() {

}
