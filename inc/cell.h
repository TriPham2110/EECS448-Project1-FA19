//-*- C++ -*-
/**
 * @file   cell.h
 * @date   17 September 2019
 * @brief  Provides a cell class which inherits from Gtk::Button to serve the purposes
 *         of playing Battleship.
 */

#ifndef CELL_H
#define CELL_H

#include <gtkmm/button.h>
#include <gtkmm/image.h>

#include <string>

//Forward Declarations
class Ship;

class Cell : public Gtk::Button {

	public:

		/**
		 * @brief Generic constructor
		 */
		Cell(Gtk::Widget* (*pImages)[6]);

        Cell();
		/**
		 * @brief Destructor
		 */
		virtual ~Cell();

		/**
		 * @pre containsShip = false
		 * @post containsShip = true
		 * @brief Places a ship in this cell
		 */
		void putShip(Ship *ptr);
    
        void cellInitImages(Gtk::Widget* (*pImages)[6]);

		/**
		 * @brief Hit this cell
		 * @pre beenHit = false
		 * @post beenHit = true
		 * @return number of hits left on the ship
		 *         9 if there is no ship in this cell
		 *         (i.e. hit is a miss)
		 */
		int hit();

		/**
		 * @brief Accessor for containsShip variable
		 */
		bool hasShip();
		/**
		 * @brief saves the location for a cell
		 */
		void set_location(int row, int col);

        /**
		 * @brief Accessor for beenHit variable
		 */
    
        void setWater();
      

	private:
        Gtk::Widget* water;
        Gtk::Widget* sunk;
        Gtk::Widget* hitI;
        Gtk::Widget* shipFront;
        Gtk::Widget* shipMid;
        Gtk::Widget* miss;
		int m_row;
		int m_col;
		bool containsShip;
		bool beenHit;
		Ship* m_ship_ptr;
    
        Gtk::Widget* (*pImages)[6];
    
};
#endif
