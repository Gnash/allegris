#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Magenta::BlockPartGraphics_Magenta(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_magenta.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Magenta::~BlockPartGraphics_Magenta(void) {
	al_destroy_bitmap(bitmapBlock);
}