//-*- C++ -*-
/**
 * @file   cell.h
 * @date   17 September 2019
 * @brief  Provides a cell class which wraps Gtk::Button to serve the purposes
 *         of playing Battleship.
 */

#ifndef CELL_H
#define CELL_H

#include <gtkmm/button.h>

//Forward Declarations
class Ship;

class Cell : public Gtk::Button {

	public:

		/**
		 * @brief Generic constructor
		 */
		Cell();

		/**
		 * @brief Constructor with positional arguments.
		 */
		Cell(int row, int col);

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

	private:
		int m_row;
		int m_col;
		bool containsShip;
		bool beenHit;
		Ship* m_ship_ptr;
};
#endif
