//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include "cell.h"
#include "ship.h"

#include <iostream>

Cell::Cell() {
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
  
    water = new Gtk::Image("img/water.png");
    hitI = new Gtk::Image("img/hit.png");
    sunk = new Gtk::Image("img/sunk.png");
    shipFront = new Gtk::Image("img/front.png");
    shipMid = new Gtk::Image("img/mid.png");
    miss = new Gtk::Image("img/miss.png");
    
    
    this->set_image(*water);
    
    water->show();
    
    
    
 
}



Cell::~Cell() {
    
    delete water;
    delete hitI;
    delete sunk;
    delete shipFront;
    delete shipMid;
    delete miss;
    

}

void Cell::set_location(int row, int col) {
	m_row = row;
	m_col = col;
}



void Cell::putShip(Ship *ship_ptr){
	containsShip = true;
	this->m_ship_ptr = ship_ptr;
    
    this->set_image(*shipFront);
    hitI->show();
    
}





int Cell::hit(){
	beenHit = true;
	if(containsShip){
        //a temp variable for whether the ship was sunk or just hit
        int i = m_ship_ptr->hit();
		if(i == 0){
            this->set_image(*sunk);
            sunk->show();
            return i;
        }
        else if(i == 1){
            this->set_image(*hitI);
            hitI->show();
            return i;
        }
	}
	else{
        this->set_image(*miss);
        miss->show();
		return 9;
	}
}



bool Cell::hasShip() {
	return (containsShip ? true : false);
}
