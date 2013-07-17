#include "InfoBox.h"
#include <allegro5/allegro_primitives.h>
#include <sstream>


InfoBox::InfoBox(int x, int y, string text, int& number, ALLEGRO_FONT* font): text(text), number(number), font(font) {
	setRelativeCoord(new Coordinate(x, y));
}


InfoBox::~InfoBox(void)
{
}


bool InfoBox::draw(void) {
	int x = getAbsoluteXPos();
	int y = getAbsoluteYPos();
	al_draw_text(font, al_map_rgb(200, 200, 200), x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());
	ostringstream ss;
	ss << number;
	string str = ss.str();
	int height = al_get_font_line_height(font);
	al_draw_text(this->font, al_map_rgb(200, 200, 200), x, y + height, ALLEGRO_ALIGN_CENTRE, str.c_str());	
	return true;
}