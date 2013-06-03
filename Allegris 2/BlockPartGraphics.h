#pragma once
#include "globals.h"
#include "GraphicsComponent.h"
//#include "Allegris.h"

using namespace std;

class BlockPartGraphics :
	public GraphicsComponent
{
public:
	BlockPartGraphics(void);
	BlockPartGraphics(GameObject* object);
	~BlockPartGraphics(void);

	virtual bool draw(void);

protected:
	ALLEGRO_BITMAP* bitmapBlock;
};