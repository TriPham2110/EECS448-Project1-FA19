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
		Ship(int size);
		~Ship();
		std::vector<Point*> getShipCoordinates();
		void addCoordinates (int x, int y);
		bool inLine (int newX, int newY, bool vert);
		void hit(int x, int y);
		bool containsCoordinate(int x, int y);
		bool isDestroyed();
};
#endif //SHIP_H
