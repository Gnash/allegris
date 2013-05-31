#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Red::BlockPartGraphics_Red(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_red.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Red::~BlockPartGraphics_Red(void) {
	al_destroy_bitmap(bitmapBlock);
}