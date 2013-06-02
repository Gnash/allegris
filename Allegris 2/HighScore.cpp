#include "HighScore.h"


HighScore::HighScore(void)
{
}

HighScore::HighScore(int points) {

}

HighScore::~HighScore(void)
{
}


bool HighScore::updateGraphic(void) {
	al_clear_to_color(al_map_rgb(255, 0, 0));
	return true;
}

bool HighScore::updateLogic(void) {
	return true;
}