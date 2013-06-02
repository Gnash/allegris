#pragma once
#include <allegro5/allegro.h>
class GameState
{
public:
	GameState(void);
	virtual ~GameState(void) = 0;

	virtual bool updateLogic(void) = 0;
	virtual bool updateGraphic(void) = 0;
	ALLEGRO_EVENT_SOURCE* getEventSource(void);
private:
	ALLEGRO_EVENT_SOURCE evSource;
};

