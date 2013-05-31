#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

const char* BITMAP_PATH = "img/block_red.bmp";

BlockPartGraphics::BlockPartGraphics(void){
	bitmapBlock = al_load_bitmap(BITMAP_PATH);
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics::~BlockPartGraphics(void) {
	al_destroy_bitmap(bitmapBlock);
}

BlockPartGraphics::BlockPartGraphics(GameObject* object) {
	this->object = object;	
	bitmapBlock = al_load_bitmap(BITMAP_PATH);
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}

bool BlockPartGraphics::draw(void) {
	bool success = true;
	int x = getObject()->getAbsoluteXPos();
	int y = getObject()->getAbsoluteYPos();
	al_draw_bitmap(bitmapBlock, x, y, 0);
	return success;
}