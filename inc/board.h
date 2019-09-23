// -*- C++ -*-
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

#include <string>


#include <gtkmm/table.h>

class Board : public Gtk::Table {

	public:

		/** TODO: Add documentation
		 * @brief Board constructor.
		 */
		Board();

		/** TODO: Add documentation
		 * @brief Board destructor.
		 */
		virtual ~Board();

		/** TODO: Add documentation
		 * @brief Place a ship in the specified cell
		 */
		void setShip(int row_num,int col_num, int size, char direction);

		/** TODO: Add documentation
		 * @brief Return whether or not the shot hit
		 */
		bool isHit(int row, int col);

		/** TODO: Add documentation
		 * @brief Return whether or not a ship was sunk
		 */
		bool isSunk();

		/** TODO: Add documentation
		 * @brief
		 */
		bool miss();

		/** TODO: Add documentation
		 * @brief
		 */
		 void putShip();

		/**
		 * @brief Attack a cell
		 */
		void hit(int row, int col);

		/**
		 * @brief set label
		 */
		void setLabel(std::string label);

	protected:
		Cell **m_board;

	private:

		int m_row;
		int m_col;

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
