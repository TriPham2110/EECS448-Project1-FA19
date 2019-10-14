// -*- C++ -*-
/**
* @file   board.cpp
* @date   13 September 2019
* @brief  Provides a gameboard
*/

#include <iostream>

#include "executive.h"
#include "board.h"
#include "cell.h"
#include "ship.h"

Board::Board(Gtk::Widget* (*pImages)[6])
	: Gtk::Table(10,10,false)
{
	bootstrap_board();
        
    std::cout << this->num_ships  << "hehe"<< std::endl;
        
    this->pImages = pImages;
}

Board::~Board() {
	//Delete each row of cells
	for(int i = 0; i < 9; i++) {
		delete m_board[i];
	}
	//Delete board
	delete m_board;
}

void Board::bootstrap_board() {
	//Board row cells is created
	this->m_board = new Cell*[9];
	//Board column of cells in created
	for(int i = 0; i < 9; i++) {
		m_board[i] = new Cell[9];
	}
    
    for(int i = 1; i<9; i++){
        for(int j = 1; j<9; j++){
            m_board[i][j].cellInitImages(pImages);
        }
    }
    
    
    
	//Sets the location of each cell and creates buttons
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			m_board[i][j].set_location(i, j);
			this->attach(m_board[i][j], j, j+1, i, i+1);
			m_board[i][j].show();
		}
	}
	for(int i = 1; i < 9; i++) {
        //sets letter labels on the columns
		char the_label = (char)64+i;
		std::string label_the;
		label_the += the_label;
		m_board[0][i].set_label(label_the);
	}
	//Label created for numbered rows on the board
	for(int i = 1; i < 9; i++) {
		m_board[i][0].set_label(std::to_string(i));
	}
}
//when a cell is clicked
void Board::makePlayable() {
	for(int m=1; m<9; m++) {
		for(int n=1; n<9; n++) {
			m_board[m][n].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Board::on_button_clicked), m, n));
		}
	}
}

void Board::makeShips(int ships, int x, int y) {
    //dont know
	m_ships = new Ship[this->num_ships];
   

	for (int i = 0; i < this->num_ships; i++){
		// make new ship of size i+1
		m_ships[i].set_size(i+1);
		this->setShip(m_ships, x, y);
	}
}

void Board::setShip(Ship* ship, int x, int y) {
	int row_num = x;
	int col_num = y;
	std::cout << row_num << ' ' << col_num << '\n';
	int size = ship->get_size();
	char direction = ship->get_direction();
	Ship* ptrShip = ship;

	// place a horizontal ship
	//if (((direction == 'h')&&(col_num + (size - 1))<9)) {
	if ((col_num + (size - 1))<9) {
		// call putShip() for each cell in that the ship occupies
		m_board[row_num][col_num].putShip(ptrShip);
		for(int i = 1;i<size;i++) {
			m_board[row_num][++col_num].putShip(ptrShip);
		}
	}
	// place a vertical ship
	//else if (((direction == 'v')&&((row_num + (size - 1))<9))) {
	else if ((col_num + (size - 1))<9) {
		// call putShip() for each cell in that the ship occupies
		m_board[row_num][col_num].putShip(ptrShip);
		for(int i = 1;i<size;i++) {
			m_board[++row_num][col_num].putShip(ptrShip);
		}
	}
	else {

	}
}

//Checks if board is empty else becomes true


void Board::hit(int row, int col) {
	if(m_board == nullptr) {
		// do nothing
	}
	else {
		int hit_outcome = m_board[row][col].hit();
		if (hit_outcome == 0){
			current_num_live_ships -= 1;
			if(current_num_live_ships == 0){
				//CURRENT PLAYER WINS GAME
			}
		}
	}
}


//Returns true or false, whether or not the ship is hit or not.
bool Board::isHit(int row, int col) {
	if(m_board[row][col].hasShip()) {
		return true;
	}
	return false;
}


//Label is created for columns on the board
void Board::setLabel(std::string label) {
	try {
		m_board[0][0].set_label(label);
	} catch (std::exception& e) {

	}
}

void Board::on_button_clicked(int x, int y) {

    num_ships = Executive::get_executive_object()->get_ship_count();
    std::cout << this->num_ships  << "hehe"<< std::endl;
    //save this for later
	//this->clear_labels();

	this->makeShips(1,x,y);

  //m_board[i][j].hit();
}

void Board::clear_labels() {
	for(int k = 1; k < 9; k++) {
		for(int m = 1; m < 9; m++) {
            
            m_board[k][m].setWater();
			
		}
	}
}

void Board::scan_for_a_hit() {
	// We only need to check one of them to be honest.
	set_hit_label_if_hit(Executive::get_executive_object()->get_clicked_row(),Executive::get_executive_object()->get_clicked_col());
}

void Board::set_hit_label_if_hit(int row, int col) {
	m_board[row][col].set_label("H");
}
