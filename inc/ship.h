#ifndef SHIP_H
#define SHIP_H

class Ship
{
	private:
		char m_direction;
		int m_size;
		int m_row;
		int m_col;
		int hits = 0;
		bool sunk = false;

	public:
		/**
		 * @brief default constructor
		 */
		Ship();

		/**
		 * @brief Ship constructor
		 */
		Ship(int row, int col, int size, char direction);

		/**
		 * @brief Ship destructor
		 */
		virtual ~Ship();

		/**
		 * @brief accessor for m_direction
		 * @return char direction
		 */
		char get_direction();

		/**
		 * @brief accessor for col
		 * @return int col
		 */
		int get_col();

		/**
		 * @brief accessor for m_row
		 * @return int row
		 */
		int get_row();

		/**
		 * @brief accessor for m_size
		 * @return int size
		 */
		int get_size();

		/**
		 * @brief accessor for sunk
		 * @return bool sunk
		 */
		bool get_sunk();

};
#endif
