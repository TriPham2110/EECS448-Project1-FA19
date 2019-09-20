//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include cell.h

Cell::Cell()
{

}

Cell::Cell(int row, int col)
{
	m_row = row;
	m_col = col;
	containsShip = false;
	beenHit = false;
}
/**
 * @pre   containsShip = false
 * @post  containsShip = true
 * @brief lets the cell know that 
 *         a ship has been placed on it
 */
void Cell::putShip(){
	containsShip = true;
}

/**
 * @pre   beenHit = false
 * @post  beenHit = true
 * @brief lets cell know that it has
 *         been hit
 */
void Cell::hit(){
	beenHit = true;
}
/**
 * @pre 
 * @post
 * @brief   accessor for containsShip
 */
bool Cell::hasShip(){
        return containsShip();
}

/**
 * @pre 
 * @post
 * @brief   accessor for beenHit
 */
bool Cell::hasBeenHit(){
	return beenHit;
}
