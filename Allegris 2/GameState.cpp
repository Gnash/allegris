#include "GameState.h"


GameState::GameState(void)
{
	al_init_user_event_source(getEventSource());
}


GameState::~GameState(void)
{
}


ALLEGRO_EVENT_SOURCE* GameState::getEventSource(void) {
	return &(this->evSource);
}
