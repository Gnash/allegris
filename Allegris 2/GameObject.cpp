#include "GameObject.h"


GameObject::GameObject(int x, int y) : parent(0), myCoord(new Coordinate(x, y)) {
}

GameObject::GameObject(void) : parent(0), myCoord(new Coordinate(0, 0)) {
}


GameObject::~GameObject(void) {
	delete myCoord;
}

Coordinate* GameObject::getRelativeCoordinate(void) {
	return myCoord;
}

int GameObject::getRelativeXPos(void) {
	return this->myCoord->getX();
}

int GameObject::getRelativeYPos(void) {
	return this->myCoord->getY();
}

int GameObject::getAbsoluteXPos(void) {
	int pX = 0;
	if (parent != 0) {
		pX = parent->getAbsoluteXPos();
	}
	return getRelativeXPos() + pX;
}

int GameObject::getAbsoluteYPos(void) {
	int pY = 0;
	if (parent) {
		pY = parent->getAbsoluteYPos();
	}
	return getRelativeYPos() + pY;
}

void GameObject::setRelativeCoord(Coordinate* coord) {
	this->myCoord = coord;
}

int GameObject::getParentXPos(void) {
	return parent->getAbsoluteXPos();
}


void GameObject::setParent(GameObject* object) {
	this->parent = object;
}

void GameObject::decreaseX(int x) {
	this->myCoord->decreaseX(x);
}

void GameObject::decreaseY(int y) {
	this->myCoord->decreaseX(y);
}

void GameObject::increaseX(int x) {
	this->myCoord->increaseX(x);
}

void GameObject::increaseY(int y) {
	this->myCoord->increaseY(y);
}

void GameObject::setRelativeCoordinate(int x, int y) {
	if (this->myCoord) {
		this->myCoord->setX(x);
		this->myCoord->setY(y);
	} else {
		this->myCoord = new Coordinate(x, y);
	}
}