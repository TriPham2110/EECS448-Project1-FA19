//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include "cell.h"
#include "ship.h"

Cell::Cell() {
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

void Cell::putShip(Ship *ship_ptr){
	containsShip = true;
	m_ship_ptr = ship_ptr;
}

int Cell::hit(){
	beenHit = true;
	if(containsShip){
		return m_ship_ptr->hit();
	}
	else{
		return 9;
	}
}

bool Cell::hasShip() {
	return (containsShip ? true : false);
}
