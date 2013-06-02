#include "Game.h"
using namespace std;

Game::Game(void){	
	this->evQueue = al_create_event_queue();
	this-> currentState = 0;
	setCurrentState(new GameWindow());
}


Game::~Game(void){
	al_destroy_event_queue(evQueue);
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
		}
	}
	return currentState->updateLogic();
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