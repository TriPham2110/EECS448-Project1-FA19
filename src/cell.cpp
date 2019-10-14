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
    
   // this->set_label("water");
    
   
    
    image = new Gtk::Image("img/water.png");
     
    
    this->set_image(*image);
    
    image->show();
    
    
    
}

Cell::Cell(int row, int col) {
	m_row = row;
	m_col = col;
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
    
    std::cout << "testtestest" << std::endl;
    
    
    //gtk_button_set_image((GtkButton*)this, image);
   //gtk_button_set_always_show_image ((GtkButton*)this, true);

}

Cell::Cell(int row, int col, std::string filename) {
	m_row = row;
	m_col = col;
	containsShip = false;
	beenHit = false;
	Ship *m_ship_ptr = nullptr;
    
   // gtk_button_set_image((GtkButton*)this, image);
    
   // gtk_button_set_always_show_image ((GtkButton*)this, true);


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
