#pragma once
#include <allegro5/allegro_font.h>
#include <vector>
#include "globals.h"
#include <allegro5/allegro_ttf.h>
class FontHandler
{
public:
	FontHandler(void);
	~FontHandler(void);

	static void loadFonts(void);
	static void destroyFonts(void);
	static ALLEGRO_FONT* getFont(int index);

private:
	static vector<ALLEGRO_FONT*> fontVector;
};

