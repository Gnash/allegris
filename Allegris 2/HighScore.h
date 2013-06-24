#pragma once
#include "gamestate.h"
#include "HighScoreList.h"

class HighScoreListEntry;

class HighScore :
	public GameState
{
public:
	HighScore(int points);
	~HighScore(void);

	bool updateGraphic(void);
	bool updateLogic(void);

private:
	HighScoreList& getHighScoreList(void);
	void loadHighScoreList(HighScoreList& list, string filePath);
	void disableInput(string &name);
	void handleNameInput(int inputUnicode, string &name);
	void setUnderscoreVisibility(bool visibility, string &name);

	HighScoreListEntry* newHighScore;
	HighScoreList highScoreList;
	bool inputMode;

	ALLEGRO_TIMER* underscoreTimer;
	bool underscoreVisible;
};

