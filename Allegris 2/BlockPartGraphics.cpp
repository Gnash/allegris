#include "blockPartGraphics.h"
#include "GameObject.h"

BlockPartGraphics::BlockPartGraphics(void){
}


BlockPartGraphics::~BlockPartGraphics(void) {
}

BlockPartGraphics::BlockPartGraphics(GameObject* object) {
	this->object = object;	
}

bool BlockPartGraphics::draw(void) {
	bool success = true;
	int x = getObject()->getAbsoluteXPos();
	int y = getObject()->getAbsoluteYPos();
	al_draw_bitmap(bitmapBlock, x, y, 0);
	return success;
}