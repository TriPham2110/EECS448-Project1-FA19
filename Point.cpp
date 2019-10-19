#include "Point.h"

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

int Point::getX() const{
    return this->x;
}

int Point::getY() const{
    return this->y;
}

std::string Point::toString() const{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool Point::operator==(const Point & p2) const {
    return (p2.x == this->x && p2.y == this->y);
}


bool Point::operator!=(const Point & p2) const { 
    return (p2.x != this->x || p2.y != this->y);
}

std::ostream & operator<<(std::ostream & os, const Point & pt){
    return os;
}

