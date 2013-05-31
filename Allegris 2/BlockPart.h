#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "BlockPartGraphics.h"
#include "BlockPartGraphics_Blue.h"
#include "BlockPartGraphics_Cyan.h"
#include "BlockPartGraphics_Green.h"
#include "BlockPartGraphics_Magenta.h"
#include "BlockPartGraphics_Red.h"
#include "BlockPartGraphics_Yellow.h"

class BlockPart :
	public GameObject
{
public:
	BlockPart(int x, int y, int blockColor);
	~BlockPart(void);
	
	bool draw(void);

	int getXIndex(void);
	int getYIndex(void);
	int getRelativeXPos(void);
	int getRelativeYPos(void);
	void setGraphicsComponent(GraphicsComponent* component);

private:
	GraphicsComponent* createBlockGraphics(int blockColor);

	GraphicsComponent* graphics;
};

