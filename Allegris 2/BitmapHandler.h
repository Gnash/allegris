#pragma once
#include <allegro5/allegro.h>
#include <vector>
#include "globals.h"
class BitmapHandler
{
public:
	BitmapHandler(void);
	~BitmapHandler(void);

	static void loadBitmaps(void);
	static void destroyBitmaps(void);
	static ALLEGRO_BITMAP* getBitmap(int index);

private:
	static vector<ALLEGRO_BITMAP*> bitmapVector;
};

