#include "Game.h"
using namespace std;

Game::Game(void){
	setCurrentState(new GameWindow());
}


Game::~Game(void){
	delete currentState;
}

bool Game::updateGraphic(void) {
	return currentState->updateGraphic();
}

bool Game::updateLogic(void) {
	return currentState->updateLogic();
}

GameState* Game::getCurrentState(void) {
	return this->currentState;
}


void Game::setCurrentState(GameState* state) {
	this->currentState = state;
}