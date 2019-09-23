// -*- C++ -*-
/**
 * @file  ship.cpp
 * @date  22 September 2019
 * @brief Provides ships
 */

#include "ship.h"

Ship::Ship()
{

}

Ship::Ship(int row, int col, int size, char direction)
{
	m_direction = direction;
	m_size = size;
	m_row = row;
	m_col = col;
}

Ship::~Ship()
{

}

char Ship::get_direction(){
	return m_direction();
}

int Ship::get_col(){
	return m_col;
}

int Ship::get_row(){
	return m_row;
}

int Ship::get_size(){
	return m_size;
}

bool Ship::get_sunk(){
	return (sunk ? true : false);
}
