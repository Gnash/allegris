#pragma once
#include "gameobject.h"
#include "Block.h"
#include "PreviewWindowGraphics.h"
#include "globals.h"
class PreviewWindow :
	public GameObject
{
public:
	PreviewWindow(void);
	PreviewWindow(int x, int y);
	virtual ~PreviewWindow(void);
	void setNextBlock(Block* nextBlock);
	bool draw();
	Block* getNextBlock(void);

private:
	Block* nextBlock;
	PreviewWindowGraphics* graphics;
};

