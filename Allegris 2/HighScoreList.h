#pragma once
#include "gameobject.h"
#include "HighScoreListEntry.h"
#include <vector>
class HighScoreList :
	public GameObject
{
public:
	HighScoreList(int x, int y);
	~HighScoreList(void);

	bool draw(void);
	HighScoreListEntry* addEntry(string name, int points);
	HighScoreListEntry* getEntry(int index);
	int size(void);

private:
	vector<HighScoreListEntry*> listEntries;
};