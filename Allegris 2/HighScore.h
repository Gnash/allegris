#pragma once
#include "gamestate.h"
class HighScore :
	public GameState
{
public:
	HighScore(void);
	HighScore(int points);
	~HighScore(void);

	bool updateGraphic(void);
	bool updateLogic(void);

private:
	
};

