//-*- C++ -*-
/**
 * @file   cell.h
 * @date   17 September 2019
 * @brief  cell class
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

		/** TODO: Add documentation
		 * @brief Destructor
		 */
		virtual ~Cell();

		/** TODO: Add documentation
		 * @pre containsShip = false
		 * @post containsShip = true
		 * @brief Places a ship in this cell
		 */
		void putShip(Ship *ptr);

		/** TODO: Add documentation
		 * @pre beenHit = false
		 * @post beenHit = true
		 * @brief Hit this cell
		 * @return number of hits left on the ship
		 *         9 if there is no ship in this cell
		 *         (i.e. hit is a miss)
		 */
		int hit();

		/** TODO: Add documentation
		 * @brief Accessor for containsShip variable
		 */
		bool hasShip();

		void set_location(int row, int col);

	private:
		int m_row;
		int m_col;
		bool containsShip;
		bool beenHit;
		Ship* m_ship_ptr;
};
#endif
