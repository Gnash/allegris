#pragma once
#include "gameobject.h"
#include "HighScoreListEntry.h"
#include <vector>
class HighScoreList :
	public GameObject
{
public:
	HighScoreList(void);
	~HighScoreList(void);

	bool draw(void);
	void addEntry(string name, int points);

private:
	vector<HighScoreListEntry> listEntries;
};