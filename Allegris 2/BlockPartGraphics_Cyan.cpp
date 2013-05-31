#include "blockPartGraphics.h"
#include <iostream>

#include "Block.h"
 
using namespace std;

BlockPartGraphics_Cyan::BlockPartGraphics_Cyan(GameObject* object){
	this->object = object;
	bitmapBlock = al_load_bitmap("img/block_cyan.bmp");
	if (!bitmapBlock) {
		 fprintf(stderr, "failed to load image!\n");
	}
}


BlockPartGraphics_Cyan::~BlockPartGraphics_Cyan(void) {
	al_destroy_bitmap(bitmapBlock);
}