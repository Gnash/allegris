#pragma once
#include "gameobject.h"
#include "BlockPart.h"
#include "PlayingField.h"
#include <vector>

using namespace std;

class Block :
	public GameObject
{
public:
	Block(void);
	virtual ~Block(void) = 0;

	bool rotate(int direction);
	int move(int direction);
	void moveBlocksToPlayingField(void);
	bool addBlockPart(BlockPart* part);
	bool draw(void);

	int getWidth(void);
	int getHeight(void);
	int getColor(void);
	int getBlockPartAmount(void);
	BlockPart* getBlockPart(int index);
	PlayingField* getPlayingField(void);
	void setWidth(int w);
	void setHeight(int h);
	void setColor(int color);
	void setPlayingField(PlayingField* field);

protected:
	void deleteBlockParts(void);

private:
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);
	bool rotateLeft(void);
	bool rotateRight(void);
	void switchWidthAndHeight(void);

	int getAbsoluteNewX(int newX, BlockPart* part);
	int getAbsoluteNewY(int newY, BlockPart* part);

	void setBlockPart(int index, BlockPart* part);

	int width;
	int height;
	int color;
	PlayingField* playingField;
	vector<BlockPart*> blockParts;
};

