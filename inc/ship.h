#ifndef SHIP_H
#define SHIP_H

class Ship
{
	private:
		char m_direction;
		int m_size;
		int m_row;
		int m_col;
		int m_hits = 0;
		bool sunk = false;

	public:
		/**
		 * @brief default constructor
		 */
		Ship();

		/**
		 * @brief Constructor for location, size, and direction.
		 */
		Ship(int row, int col, int size, char direction);

		/**
		 * @brief Constructor with size only.
		 */
		Ship(int size);

		/**
		 * @brief Ship destructor
		 */
		virtual ~Ship();

		/**
		 * @brief Update ship with its location and orientation
		 */
		void updateShip(int row, int col, char direction);

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
		 *
		 *
		 */
		void set_size(int size);

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

		/**
		 * @post hits counter is increased by 1
		 * @brief hit the ship
		 * @return number of hits left (m_size - hits)
		 */
		int hit();

};
#endif
