#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Yellow::BlockPartGraphics_Yellow(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_yellow.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Yellow::~BlockPartGraphics_Yellow(void) {
	al_destroy_bitmap(bitmapBlock);
}