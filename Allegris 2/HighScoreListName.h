#pragma once
#include "gameobject.h"
#include <allegro5/allegro.h>
class HighScoreListName :
	public GameObject
{
public:
	HighScoreListName(int x, int y, string name);
	~HighScoreListName(void);

	bool draw(void);

private:
	string name;
};

