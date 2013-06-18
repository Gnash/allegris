#pragma once
#include "gameobject.h"
#include "HighScoreListName.h"
#include "HighScoreListPoints.h"
class HighScoreListEntry :
	public GameObject
{
public:	
	~HighScoreListEntry(void);
	HighScoreListEntry(int x, int y, string name, int points);
	bool draw(void) ;

private:
	HighScoreListName entryName;
	HighScoreListPoints entryPoints;
};

