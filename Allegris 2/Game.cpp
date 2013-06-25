#include "Game.h"
using namespace std;

Game::Game(void){	
	this->evQueue = al_create_event_queue();
	al_init_user_event_source(getEventSource());
	this-> currentState = 0;
	setCurrentState(new GameMenu());
}


Game::~Game(void){
	al_destroy_event_queue(evQueue);
	al_destroy_user_event_source(getEventSource());
	delete currentState;
}

bool Game::updateGraphic(void) {
	return currentState->updateGraphic();
}

bool Game::updateLogic(void) {
	ALLEGRO_EVENT ev;
	while (!al_event_queue_is_empty(evQueue)) {
		al_wait_for_event(evQueue, &ev);
		if (ev.type == ALLEGRO_GET_EVENT_TYPE('l', 'o', 's', 't')) {
			setCurrentState(new HighScore(ev.user.data1));
		} else if (ev.type == ALLEGRO_GET_EVENT_TYPE('s', 't', 'r', 't')) {
			setCurrentState(new GameWindow());
		} else if (ev.type == ALLEGRO_GET_EVENT_TYPE('c', 'l', 'o', 's')) {
			emitCloseEvent();
		} else if (ev.type == ALLEGRO_GET_EVENT_TYPE('h', 'i', 'g', 'h')) {
			setCurrentState(new HighScore());
		} else if (ev.type == ALLEGRO_GET_EVENT_TYPE('m', 'e', 'n', 'u')) {
			setCurrentState(new GameMenu());
		}
	}
	return currentState->updateLogic();
}

void Game::emitCloseEvent(void) {
	ALLEGRO_EVENT ev;
	ev.type = ALLEGRO_GET_EVENT_TYPE('c', 'l', 'o', 's');
	al_emit_user_event(getEventSource(), &ev, 0);
}

GameState* Game::getCurrentState(void) {
	return this->currentState;
}

ALLEGRO_EVENT_QUEUE* Game::getEventQueue(void) {
	return this->evQueue;
}

void Game::setCurrentState(GameState* state) {
	al_unregister_event_source(getEventQueue(), getCurrentState()->getEventSource());
	if (this->currentState) {
		delete this->currentState;
	}
	this->currentState = state;
	al_register_event_source(getEventQueue(), state->getEventSource());
}

ALLEGRO_EVENT_SOURCE* Game::getEventSource(void) {
	return &(this->evSource);
}