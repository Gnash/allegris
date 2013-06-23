#pragma once
#include "gameobject.h"
#include "HighScoreListName.h"
#include "HighScoreListPoints.h"
class HighScoreListEntry :
	public GameObject
{
public:	
	~HighScoreListEntry(void);
	HighScoreListEntry(int x, int y, int width, string name, int points);
	bool draw(void) ;

	string getName(void);
	void setName(string newName);

	void setActive(bool active);

private:
	HighScoreListName entryName;
	HighScoreListPoints entryPoints;

	bool active;
};

