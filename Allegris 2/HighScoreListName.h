#pragma once
#include "gameobject.h"
#include <allegro5/allegro.h>
class HighScoreListName :
	public GameObject
{
public:
	HighScoreListName(void);
	~HighScoreListName(void);

	string name;
};

