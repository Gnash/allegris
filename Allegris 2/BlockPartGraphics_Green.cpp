#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Green::BlockPartGraphics_Green(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_green.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Green::~BlockPartGraphics_Green(void) {
	al_destroy_bitmap(bitmapBlock);
}