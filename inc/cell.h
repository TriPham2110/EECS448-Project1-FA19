//-*- C++ -*-
/**
 * @file   cell.h
 * @date   17 September 2019
 * @brief  cell class
 */

#ifndef CELL_H
#define CELL_H

//Forward Declarations
class Cell {

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
		void putShip();

		/** TODO: Add documentation
		 * @pre beenHit = false
		 * @post beenHit = true
		 * @brief Hit this cell
		 */
		void hit();

		/** TODO: Add documentation
		 * @brief Accessor for containsShip variable
		 */
		bool hasShip();


	private:
		int m_row;
		int m_col;
		bool containsShip;
		bool beenHit;

};
#endif
