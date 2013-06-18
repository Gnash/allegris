#include "HighScoreListPoints.h"
#include <sstream>


HighScoreListPoints::HighScoreListPoints(int x, int y, int points) : points(points), font(FontHandler::getFont(FONT_INDEX_HIGHSCORE))
{;
	setRelativeCoord(new Coordinate(x, y));
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