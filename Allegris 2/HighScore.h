#pragma once
#include "gamestate.h"
#include "HighScoreList.h"

class HighScoreListEntry;

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
	void loadHighScoreList(HighScoreList& list, string filePath);
	void saveHighScoreList(HighScoreList& list, string filePath);
	void disableInput(string &name);
	void handleNameInput(int inputUnicode, string &name);
	void setUnderscoreVisibility(bool visibility, string &name);
	void emitMainMenuEvent(void);

	HighScoreListEntry* newHighScore;
	HighScoreList highScoreList;
	bool inputMode;
	
	ALLEGRO_FONT* font;
	ALLEGRO_TIMER* underscoreTimer;
	bool underscoreVisible;
};

