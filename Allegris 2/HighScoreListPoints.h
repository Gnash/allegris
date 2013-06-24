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
	HighScoreListPoints(int x, int y, int points);
	~HighScoreListPoints(void);

	bool draw(void);
	int getPoints(void);

private:
	int points;
	ALLEGRO_FONT* font;
};

