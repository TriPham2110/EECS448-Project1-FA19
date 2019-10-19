#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iostream>
#include "Point.h"
#include <string>

class Ship{
	private:
		std::vector<Point*> shipCoordinates;
		int shipSize;
		int shipPieces;

	public:
		/*
		 * @ pre none
		 *	@ param size
		 *	@ post constructor
		 * @ return none
		 */
		Ship(int size);
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post deconstructor
		 * @ return none
		 */
		~Ship();
		/*
		 * @ pre none
		 *	@ param none
		 *	@ post gets ships coordinates
		 * @ return return ships coordinates
		 */
		std::vector<Point*> getShipCoordinates();
		/*
		 * @ pre none
		 *	@ param x and y coordinates
		 *	@ post adds addCoordinates
		 * @ return none
		 */
		void addCoordinates (int x, int y);
		/*
		 * @ pre none
		 *	@ param new x and y coordinates and vertical or not
		 *	@ post check whether the points are aligned
		 * @ return true or false if its inline or not
		 */
		bool inLine (int newX, int newY, bool vert);
		/*
		 * @ pre a hit has to made on a ship
		 *	@ param x and y coordinates
		 *	@ post if hit, shipPieces are decresed
		 * @ return none
		 */
		void hit(int x, int y);
		/*
		 * @ pre none
		 *	@ param x and y coordinates
		 *	@ post contains coordinates or not
		 * @ return true or false if these coordinates are there or not
		 */
		bool containsCoordinate(int x, int y);
		/*
		 * @ pre a ship has to be sunk
		 *	@ param none
		 *	@ post ship is destoryed or not
		 * @ return true or false on if the ship is destroyed
		 */
		bool isDestroyed();
};
#endif //SHIP_H
