#pragma once
#include "gameobject.h"
class HighScoreList :
	public GameObject
{
public:
	HighScoreList(void);
	~HighScoreList(void);

	bool draw(void);
};

