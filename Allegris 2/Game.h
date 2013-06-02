#pragma once
#include "GameState.h"
#include <allegro5/allegro.h>
#include "GameWindow.h"
#include "GameMenu.h"
#include "HighScore.h"
#include "globals.h"

class Game
{
public:
	Game(void);
	~Game(void);

	bool updateLogic(void);
	bool updateGraphic(void);

	void setCurrentState(GameState* state);
	GameState* getCurrentState(void);
	
private:
	ALLEGRO_EVENT_QUEUE* getEventQueue(void);

	GameState *currentState;
	ALLEGRO_EVENT_QUEUE *evQueue;
};

