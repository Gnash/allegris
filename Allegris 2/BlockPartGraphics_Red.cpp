#include "blockPartGraphics_red.h"

BlockPartGraphics_Red::BlockPartGraphics_Red(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_RED);
}


BlockPartGraphics_Red::~BlockPartGraphics_Red(void) {
}