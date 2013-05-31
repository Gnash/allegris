#include "Coordinate.h"


Coordinate::Coordinate(int x, int y){
	this->x = x;
	this->y = y;
}

Coordinate::Coordinate(void) {
	this->x = 0;
	this->y = 0;
}


Coordinate::~Coordinate(void){
}

int Coordinate::getX(void) {
	return this->x;
}

int Coordinate::getY(void) {
	return this->y;
}

void Coordinate::decreaseX(int x) {
	this->x -= x;
}

void Coordinate::decreaseY(int y) {
	this->y -= y;
}

void Coordinate::increaseX(int x) {
	this->x += x;
}

void Coordinate::increaseY(int y) {
	this->y += y;
}

void Coordinate::setX(int x) {
	this->x = x;
}

void Coordinate::setY(int y) {
	this->y = y;
}