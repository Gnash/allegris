#include "blockPartGraphics_magenta.h"
using namespace std;

BlockPartGraphics_Magenta::BlockPartGraphics_Magenta(GameObject* object){
	this->object = object;
	bitmapBlock = BitmapHandler::getBitmap(BITMAP_INDEX_BLOCK_MAGENTA);
}


BlockPartGraphics_Magenta::~BlockPartGraphics_Magenta(void) {
}