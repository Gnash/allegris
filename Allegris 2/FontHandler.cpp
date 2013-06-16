#include "FontHandler.h"

vector<ALLEGRO_FONT*> FontHandler::fontVector;

FontHandler::FontHandler(void)
{
}


FontHandler::~FontHandler(void)
{
}


ALLEGRO_FONT* FontHandler::getFont(int index) {
	if (index < 0 || index >= fontVector.size()) {
		return 0;
	} else {
		return fontVector.at(index);
	}
}

void FontHandler::loadFonts(void) {
	fontVector.push_back(al_load_ttf_font("font/VideoTerminalScreen.ttf",30,0 ));
	fontVector.push_back(al_load_ttf_font("font/VideoTerminalScreen.ttf",30,0 ));
}

void FontHandler::destroyFonts(void) {
	vector<ALLEGRO_FONT*>::iterator it;
	for (it = fontVector.begin(); it != fontVector.end(); it++){
		al_destroy_font(*it);
	}
}