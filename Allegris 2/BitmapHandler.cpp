#include "BitmapHandler.h"

vector<ALLEGRO_BITMAP*> BitmapHandler::bitmapVector;

BitmapHandler::BitmapHandler(void)
{
}


BitmapHandler::~BitmapHandler(void)
{
}


ALLEGRO_BITMAP* BitmapHandler::getBitmap(int index) {
	if (index < 0 || index >= bitmapVector.size()) {
		return 0;
	} else {
		return bitmapVector.at(index);
	}
}

void BitmapHandler::loadBitmaps(void) {
	bitmapVector.push_back(al_load_bitmap("img/block_blue.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_cyan.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_green.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_magenta.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_orange.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_red.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/block_yellow.bmp"));
	bitmapVector.push_back(al_load_bitmap("img/previewWindow.png"));
}

void BitmapHandler::destroyBitmaps(void) {
	vector<ALLEGRO_BITMAP*>::iterator it;
	for (it = bitmapVector.begin(); it != bitmapVector.end(); it++){
		al_destroy_bitmap(*it);
	}
}