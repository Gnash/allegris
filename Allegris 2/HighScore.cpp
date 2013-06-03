#include "HighScore.h"


HighScore::HighScore(void)
{
}

HighScore::HighScore(int points) {
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
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

