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
	: Gtk::Table(10,10,false)
{
	bootstrap_board();
}

Board::~Board() {
        // delete each row of cells
	for(int i = 0; i < 9; i++) {
		delete m_board[i];
	}
        // delete the board
	delete m_board;
}

void Board::bootstrap_board() {
        // create board rows of cells
	this->m_board = new Cell*[9];
        //create boad columns of cells
	for(int i = 0; i < 9; i++) {
		m_board[i] = new Cell[9];
	}
        // set the location of each cell and show it
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			m_board[i][j].set_location(i, j);
			this->attach(m_board[i][j], j, j+1, i, i+1);
			m_board[i][j].show();
		}
	}
	for(int i = 1; i < 9; i++) {
		// Trying to do this the clever way by casting int to char inside to_string
		// inside the set_label call did not work and just labelled them with letters.
		// TRUST ME, I hate this code as much as you do right now.
		char the_label = (char)64+i;
		std::string label_the;
		label_the += the_label;
		m_board[0][i].set_label(label_the);
	}
        // label the rows with numbers 1 to 9
	for(int i = 1; i < 9; i++) {
		m_board[i][0].set_label(std::to_string(i));
	}
}

void Board::makeShips(int num_ships){
	initial_num_ships = num_ships;
	current_num_live_ships = num_ships;
	m_ships = new Ship[num_ships];

	for (int i = 0; i < num_ships; ++i){
		// make new ship of size i+1
		m_ships[i] = new Ship(i+1);
	}
}

void Board::setShip(Ship ship)
{
        row_num = ship.get_row();
        col_num = ship.get_col();
	size = ship.get_size();
	direction = ship.get_direction();

	ptrShip = &ship;

	if((direction == 'h')&&((col_num + (size - 1))<8))
        // place a horizontal ship
	{
                
                // call putShip() for each cell in that the ship occupies
		m_board[row_num][col_num].putShip(ptrShip);
		for(int i = 1;i<size;i++)
		{
			m_board[row_num][++col_num].putShip(ptrShip);
		}
	}

	else if ((direction == 'v')&&((row_num + (size - 1))<8))
        // place a vertiacal ship
	{
                 
                // call putShip() for each cell in that the ship occupies
		m_board[row_num][col_num].putShip(ptrShip);
		for(int i = 1;i<size;i++)
		{
			m_board[++row_num][col_num].putShip(ptrShip);
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
                // call hit() on the cell
int hit_outcome = m_board[row][col].hit();
		if (hit_outcome == 0){
			current_num_live_ships -= 1;
			if(current_num_live_ships == 0){
				//CURRENT PLAYER WINS GAME
			}
		}
	}
}

bool Board::isHit(int row, int col) {
        //return whether or not the attack hit a ship or missed
	if(m_board[row][col].hasShip())
		{
			return true;
		}
		return false;
}

bool Board::isSunk() {

}

void Board::setLabel(std::string label) {
	try {
		m_board[0][0].set_label(label);
	} catch (std::exception& e) {
		std::cout << "Cannot set label of unallocated board." << std::endl;
	}
}
