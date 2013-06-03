#include "HighScoreListPoints.h"


HighScoreListPoints::HighScoreListPoints(int points)
{
	this->points = points;
	this->font = FontHandler::getFont(
}


HighScoreListPoints::~HighScoreListPoints(void)
{
}


bool HighScoreListPoints::draw(void) {
	al_draw_text(this->font, al_map_rgb(0, 0, 200), getAbsoluteXPos(), getAbsoluteYPos(), ALLEGRO_ALIGN_RIGHT, points);
	return true;
}