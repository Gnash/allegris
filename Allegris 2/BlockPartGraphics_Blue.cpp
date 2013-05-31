#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Blue::BlockPartGraphics_Blue(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_blue.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Blue::~BlockPartGraphics_Blue(void) {
	al_destroy_bitmap(bitmapBlock);
}