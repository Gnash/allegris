#include "blockPartGraphics_green.h"
 
using namespace std;

BlockPartGraphics_Green::BlockPartGraphics_Green(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_GREEN);
}


BlockPartGraphics_Green::~BlockPartGraphics_Green(void) {
}