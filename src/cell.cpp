//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include "cell.h"

Cell::Cell() {
	containsShip = false;
	beenHit = false;
}

Cell::Cell(int row, int col) {
	m_row = row;
	m_col = col;
	containsShip = false;
	beenHit = false;
}

Cell::~Cell() {

}
//Saves the location of a cell
void Cell::set_location(int row, int col) {
	m_row = row;
	m_col = col;
}

//Used for placing a ship in a sell
void Cell::putShip() {
	containsShip = true;
}
//Used for determining to hit a cell or not.
void Cell::hit(){
	beenHit = true;
}
 
bool Cell::hasShip() {
	return (containsShip ? true : false);
}
