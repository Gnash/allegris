#pragma once
#include "gameobject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "globals.h"
#include "FontHandler.h"
class HighScoreListName :
	public GameObject
{
public:
	HighScoreListName(int x, int y, string name);
	~HighScoreListName(void);

	bool draw(void);
	string getName(void);
	void setName(string newName);

private:
	string name;
	ALLEGRO_FONT* font;
};

