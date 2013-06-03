#pragma once
#include "gameobject.h"
#include "globals.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
class MenuItem :
	public GameObject
{
public:
	MenuItem(void);
	MenuItem(GameObject* parent, string text, int index);
	~MenuItem(void);

	bool draw(void);
	bool isActive(void);
	void setActive(bool);
	int getIndex(void);
	void setIndex(int index);
	string getText(void);
	void setText(string text);

private:
	string text;	
	bool active;
	int index;
	ALLEGRO_FONT* font;
};

