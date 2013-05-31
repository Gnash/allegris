#pragma once
#include "gameobject.h"
#include "BlockPart.h"
#include <vector>

class BlockLine :
	public GameObject
{
public:
	BlockLine(int y);
	~BlockLine(void);

	void draw(void);
	void initializeBlockParts(void);
	bool addBlockPart(int index, BlockPart *part);
	bool isEmpty(void);
	bool isComplete(void);
	BlockPart* getBlockPart(int index);
	BlockPart* getBlockPartByCoordinate(int y);
	bool setBlockPart(int index, BlockPart* part);

private:
	vector<BlockPart*> blockParts;
};

