#pragma once
#include "gameobject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "globals.h"
#include "FontHandler.h"
class HighScoreListPoints :
	public GameObject
{
public:
	HighScoreListPoints(int points);
	~HighScoreListPoints(void);

	bool draw(void);

private:
	int points;
	ALLEGRO_FONT* font;
};

