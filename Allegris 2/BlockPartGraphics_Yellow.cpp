#include "blockPartGraphics_yellow.h"

BlockPartGraphics_Yellow::BlockPartGraphics_Yellow(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_YELLOW);
}


BlockPartGraphics_Yellow::~BlockPartGraphics_Yellow(void) {
}