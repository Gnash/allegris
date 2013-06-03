#include "blockPartGraphics_Cyan.h"
 
using namespace std;

BlockPartGraphics_Cyan::BlockPartGraphics_Cyan(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_CYAN);
}


BlockPartGraphics_Cyan::~BlockPartGraphics_Cyan(void) {
}