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
		 * @brief
		 */
		virtual ~Cell();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void putShip();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */

		/** TODO: Add documentation
		 * @brief
		 */
		void hit();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		bool hasShip();

		void set_location(int row, int col);

	private:
		int m_row;
		int m_col;
		bool containsShip;
		bool beenHit;

};
#endif
