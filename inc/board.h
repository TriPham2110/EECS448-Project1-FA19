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

    	//void setShip(Ship ship);

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
		/**
		 * @brief  Places a ship in the specified cell based on orientation
		 * @param Takes in the row number, col number, size of the ship, and the direction and sets it on the cell
		 */
		void setShip(Ship* ship);

				/**
				 * @brief ALlows interaction with the board, by choosing spots
				 */

		void makePlayable();

		void scan_for_a_hit();

		void set_hit_label_if_hit(int row, int col);

		void clear_labels();
	protected:
		Cell **m_board;

				/**
				 * @pre Board is set up
				 * @brief Sets labels for the board, for the rows and columns
				 */

		void on_button_clicked(int i, int j);

	private:

		int m_row;
		int m_col;
		int shipHits;
		int shipLength;
		int initial_num_ships;
		int current_num_live_ships;
		bool playable;
		Ship *m_ships;

		/**
		 * @brief Syntactic sugar that allows us to add buttons to the field
		 *        without polluting the constructor.
		 */
		void add_playfield_button();

		/**
		 * @brief Arranges correct amount of rows/cols
		 */
		void bootstrap_board();

		/**
		 * @brief make ships
		 * @param int the number of ships to be made
		 */
		void makeShips(int num_ships);

};

#endif // BOARD_H_
