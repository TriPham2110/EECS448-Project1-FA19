// -*- C++ i-*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the boards the user monitors/interacts with.
*/

#ifndef BOARD_H
#define BOARD_H

#define ROWS 8
#define COLS 8

// Forward Declarations
class Cell;
class Ship;

#include <string>

#include <gtkmm/table.h>

class Board : public Gtk::Table {

	public:
		/**
		 * @brief Board constructor.
		 */
		Board();

		/**
		 * @brief Board destructor.
		 */
		virtual ~Board();

		/**
		 * @brief  Places a ship in the specified cell based on orientation
		 * @param Takes in the row number, col number, size of the ship, and the direction and sets it on the cell
		 */
		void setShip(int row_num,int col_num, int size, char direction);

		/**
		 * @param Checks the row and column
		 * @post Returns true or false based on if a cell has been hit.
		 * @brief Checks to see if a cell has been hit and returns true if it has.
		 */

		bool isHit(int row, int col);

		/** TODO: Add documentation
		 * @brief
		 */
		bool isSunk(int row, int col);

		/**
		 * @param Checks the row and column
		 * @post Returns true if board is not empty
		 * @brief Checks if the board is empty or not, if not returns true..
		 */

		void hit(int row, int col);

		/**
		 * @pre Board is set up
		 * @brief Sets labels for the board, for the rows and columns
		 */

		void setLabel(std::string label);

		void makeShips(int num_ships);

		void setShip(Ship* ship);

	protected:
		Cell **m_board;

	private:

		int m_row;
		int m_col;
		int shipHits;
		int shipLength;

		/**
		 * @brief Syntactic sugar that allows us to add buttons to the field
		 *        without polluting the constructor.
		 */
		void add_playfield_button();

		/**
		 * @brief Arranges correct amount of rows/cols
		 */
		void bootstrap_board();

};

#endif // BOARD_H_
