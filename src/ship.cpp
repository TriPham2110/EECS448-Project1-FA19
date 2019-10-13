// -*- C++ -*-
/**
 * @file  ship.cpp
 * @date  22 September 2019
 * @brief Provides ships
 */

#include "ship.h"

#include <iostream>

Ship::Ship()
{
    std::cout << "testestsetsetalksfjlkajsdfljkfasdljkfdsjklfdsjkl" << std::endl;

}

Ship::Ship(int size)
{
	m_size = size;
	m_hits = 0;
}

Ship::~Ship()
{

}

void Ship::updateShip(int row, int col, char direction){

	m_direction = direction;
	m_row = row;
	m_col = col;
}

char Ship::get_direction(){
	return m_direction;
}

int Ship::get_col(){
	return m_col;
}

int Ship::get_row(){
	return m_row;
}

void Ship::set_size(int size) {
	m_size = size;
}

int Ship::get_size(){
	return m_size;
}

bool Ship::get_sunk(){
	return (sunk ? true : false);
}

int Ship::hit(){
	if (sunk){
		return 0;
	}
	else{
		m_hits += 1;
		if (m_hits == m_size){
			sunk = true;
		}
		return (m_size - m_hits);
	}
}
