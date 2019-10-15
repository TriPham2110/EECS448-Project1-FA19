#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iostream>
#include "Point.h"
#include <string>
using namespace std;

class Ship
{
public:
    Ship(int size);
    ~Ship();
    std::vector<Point*> getShipCoordinates();
    void addCoordinates (int x, int y);
    bool inLine (int newX, int newY);
    void hit(int x, int y);
    bool containsCoordinate(int x, int y);
    bool isDestroyed();
private:
    std::vector<Point*> shipCoordinates;
    int shipSize;
    int shipPieces;
};

#endif //SHIP_H
