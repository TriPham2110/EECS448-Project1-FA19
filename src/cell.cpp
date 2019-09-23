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

void Cell::set_location(int row, int col) {
	m_row = row;
	m_col = col;
}

void Cell::putShip() {
	containsShip = true;
}

void Cell::hit(){
	beenHit = true;
}

bool Cell::hasShip() {
	return (containsShip ? true : false);
}
