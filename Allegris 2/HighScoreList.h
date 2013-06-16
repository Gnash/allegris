#pragma once
#include "gameobject.h"
#include "HighScoreListEntry.h"
class HighScoreList :
	public GameObject
{
public:
	HighScoreList(void);
	~HighScoreList(void);

	bool const draw(void);

private:
	vector<HighScoreListEntry>
};

