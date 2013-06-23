#include "HighScoreListName.h"


HighScoreListName::HighScoreListName(int x, int y, string name): name(name), font(FontHandler::getFont(FONT_INDEX_HIGHSCORE))
{
	setRelativeCoord(new Coordinate(x, y));
}


HighScoreListName::~HighScoreListName(void)
{
}


bool HighScoreListName::draw(void) {
	al_draw_text(this->font, al_map_rgb(0, 0, 200), getAbsoluteXPos(), getAbsoluteYPos(), ALLEGRO_ALIGN_LEFT, this->name.c_str());
	return true;
}