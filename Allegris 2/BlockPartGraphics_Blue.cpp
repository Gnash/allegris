#include "blockPartGraphics_blue.h"
 
using namespace std;

BlockPartGraphics_Blue::BlockPartGraphics_Blue(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_BLUE);
}


BlockPartGraphics_Blue::~BlockPartGraphics_Blue(void) {
}