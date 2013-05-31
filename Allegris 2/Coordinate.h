#pragma once
class Coordinate
{
public:
	Coordinate(int x, int y);
	Coordinate(void);
	~Coordinate(void);

	int getX(void);
	int getY(void);
	void setX(int x);
	void setY(int y);
	void increaseX(int x);
	void increaseY(int y);
	void decreaseX(int x);
	void decreaseY(int y);

private:
	int x;
	int y;
};

