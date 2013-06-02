#pragma once
#include "GameState.h"
class GameMenu:
	public GameState
{
public:
	GameMenu(void);
	~GameMenu(void);

	bool updateLogic(void);
	bool updateGraphic(void);
};

