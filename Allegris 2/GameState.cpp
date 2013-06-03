#include "GameState.h"


GameState::GameState(void)
{
	al_init_user_event_source(getEventSource());
	this->evQueue = al_create_event_queue();
}


GameState::~GameState(void)
{
	al_destroy_event_queue(evQueue);
	al_destroy_user_event_source(getEventSource());
}


ALLEGRO_EVENT_SOURCE* GameState::getEventSource(void) {
	return &(this->evSource);
}

ALLEGRO_EVENT_QUEUE* GameState::getEventQueue(void) {
	return this->evQueue;
}
