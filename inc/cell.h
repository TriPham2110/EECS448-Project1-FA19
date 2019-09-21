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
		/**TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void putShip();
		
		/**TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */

		void hit();
                
		/**TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
                bool hasShip();

		/**TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
                bool hasBeenHit();


	private:
		int row;
		int col;
		bool containsShip;
		bool beenHit;

};
#endif
