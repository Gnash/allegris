#pragma once
#include "gamestate.h"
#include "HighScoreList.h"
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
	HighScoreList& getHighScoreList(void);

	HighScoreList highScoreList;
};

