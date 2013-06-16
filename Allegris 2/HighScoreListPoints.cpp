#include "HighScoreListPoints.h"
#include <sstream>


HighScoreListPoints::HighScoreListPoints(int points)
{
	this->points = points;
	this->font = FontHandler::getFont(FONT_INDEX_HIGHSCORE);
}


HighScoreListPoints::~HighScoreListPoints(void)
{
}


bool HighScoreListPoints::draw(void) {
	ostringstream ss;
	ss << points;
	string str = ss.str();
	al_draw_text(this->font, al_map_rgb(0, 0, 200), getAbsoluteXPos(), getAbsoluteYPos(), ALLEGRO_ALIGN_RIGHT, str.c_str());
	return true;
}