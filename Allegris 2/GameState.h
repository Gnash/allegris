#pragma once
class GameState
{
public:
	GameState(void);
	virtual ~GameState(void) = 0;

	virtual bool updateLogic(void) = 0;
	virtual bool updateGraphic(void) = 0;
};

