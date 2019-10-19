#include "Ship.h"

Ship::Ship(int size){
	this->shipSize = size;
	this->shipPieces = size;
}

Ship::~Ship(){
	while(!shipCoordinates.empty()){
		delete shipCoordinates.back();
		shipCoordinates.back() = NULL;
		shipCoordinates.pop_back();
	}
}

std::vector<Point*> Ship::getShipCoordinates(){
	return shipCoordinates;
}

void Ship::addCoordinates(int x, int y){
	shipCoordinates.push_back(new Point(x,y));
}

bool Ship::inLine(int newX, int newY, bool vert){
	if(shipCoordinates.size() == 0){
		return true;
	}
	for(Point *shipPiece : shipCoordinates){
		int x = (int)shipPiece->getX();
		int y = (int)shipPiece->getY();
		if(newX == x && (newY == y + 1 || newY == y - 1) && (!vert || shipCoordinates.size() == 1)){
			return true;
		}
		else if(newY == y && (newX == x + 1 || newX == x - 1) && (vert || shipCoordinates.size() == 1)){
			return true;
		}
	}
	return false;
}

void Ship::hit(int x, int y){
	shipPieces--;
}

bool Ship::containsCoordinate(int x, int y){
	if(0 == shipCoordinates.size()){
		return false;
	}
	else if(x >= 0 && x <= 7 && y >= 0 && y <= 7){
		for(int i = 0; i < (int)shipCoordinates.size(); i++){
			int cordX = (int)shipCoordinates.at(i)->getX();
			int cordY = (int)shipCoordinates.at(i)->getY();
			if(cordX == x && cordY == y){
				return true;
			}
		}
	}
	return false;
}

bool Ship::isDestroyed(){
	if(shipPieces <= 0){
		return true;
	}
	return false;
}
