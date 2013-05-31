#pragma once
#include "Coordinate.h"
#include "globals.h"

class GameObject
{
public:
	GameObject(void);
	GameObject(int x, int y);
	virtual ~GameObject(void) = 0;

	virtual int getRelativeXPos(void);
	virtual int getRelativeYPos(void);
	int getAbsoluteXPos(void);
	int getAbsoluteYPos(void);
	void decreaseX(int x);
	void decreaseY(int y);
	void increaseX(int x);
	void increaseY(int y);
	void setRelativeCoordinate(int x, int y);
	
	void setParent(GameObject* object);

protected:
	Coordinate* getRelativeCoordinate(void);
	int getParentXPos(void);
	int getParentYPos(void);
	void setRelativeCoord(Coordinate* coord);

private:
	Coordinate *myCoord;
	GameObject *parent;
};

