//-*- C++ -*-
/**
 * @file   cell.cpp
 * @date   17 September 2019
 * @brief  cell class
 */

#include "cell.h"
#include "ship.h"

#include <iostream>

Cell::Cell(){
    containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
}

Cell::Cell(Gtk::Widget* (*pImages)[6]) {
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
    
    
    this->set_image(*water);
    
    this->pImages = pImages;
    
    this->set_image(**(pImages)[0]);
    
    //(pImages)[0]->show();

}


void Cell::cellInitImages(Gtk::Widget* (*pImages)[6]){
    
    //this->pImages = pImages;
    
    this->set_image(*new Gtk::Image("img/water.png"));
}


Cell::~Cell() {
    

    

}

void Cell::set_location(int row, int col) {
	m_row = row;
	m_col = col;
}



void Cell::putShip(Ship *ship_ptr){
	containsShip = true;
	this->m_ship_ptr = ship_ptr;
    
    this->set_image(**(pImages)[3]);
    //**(pImages)[3]->show();
    
}

void Cell::setWater(){  
    this->set_image(**(pImages)[0]);
    
   // **(pImages)[0]->show();  
}





int Cell::hit(){
	beenHit = true;
	if(containsShip){
        //a temp variable for whether the ship was sunk or just hit
        int i = m_ship_ptr->hit();
		if(i == 0){
            this->set_image(**(pImages)[2]);
            //**(pImages)[2]->show();
            return i;
        }
        else if(i == 1){
            this->set_image(**(pImages)[1]);
            //**(pImages)[1]->show();
            return i;
        }
	}
	else{
        this->set_image(**(pImages)[5]);
        //**(pImages)[5]->show();
		return 9;
	}
}



bool Cell::hasShip() {
	return (containsShip ? true : false);
}
