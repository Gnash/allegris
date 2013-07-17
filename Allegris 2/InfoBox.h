#pragma once
#include "gameobject.h"
#include <allegro5/allegro_font.h>
class InfoBox :
	public GameObject
{
public:
	InfoBox(int x, int y, string text, int& number, ALLEGRO_FONT* font);
	InfoBox(void);
	~InfoBox(void);

	bool draw(void);

private:
	string text;
	int& number;
	ALLEGRO_FONT* font;
};

