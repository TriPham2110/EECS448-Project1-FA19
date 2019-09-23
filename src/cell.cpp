//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include "cell.h"

Cell::Cell(){
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
}

Cell::Cell(int row, int col) {
	m_row = row;
	m_col = col;
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
}

Cell::~Cell() {

}

void Cell::set_location(int row, int col) {
	m_row = row;
	m_col = col;
}

/**
 * @pre   containsShip = false
 * @post  containsShip = true
 * @brief lets the cell know that 
 *         a ship has been placed on it
 */
void Cell::putShip(Ship *ship_ptr){
	containsShip = true;
	m_ship_ptr = ship_ptr;
}

/**
 * @pre   beenHit = false
 * @post  beenHit = true
 * @brief lets cell know that it has
 *         been hit
 * @return number of hits left on the ship
 *         9 if there is no ship in this cell
 */
int Cell::hit(){
	beenHit = true;
	if(m_containsShip){
		return m_ship_ptr->hit();
	}
	else{
		return 9;
	}
}

/**
 * @brief accessor for containsShip
 */

bool Cell::hasShip(){
        return (containsShip ? true : false);
}
