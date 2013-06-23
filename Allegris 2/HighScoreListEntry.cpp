#include "HighScoreListEntry.h"
#include <allegro5/allegro_primitives.h>


HighScoreListEntry::HighScoreListEntry(int x, int y, int width, string name, int points) 
		: entryName(x + 10, y + 10, name), entryPoints(x + width - 10, y + 10, points) {
	entryName.setParent(this);
	entryPoints.setParent(this);
	this->setRelativeCoord(new Coordinate(x, y));
	
}


HighScoreListEntry::~HighScoreListEntry(void)
{
}


bool HighScoreListEntry::draw(void) {
	bool result = true;
	if (active) {
		al_draw_rectangle(getAbsoluteXPos(), getAbsoluteYPos(), getAbsoluteXPos() + HIGHSCORE_LIST_WIDTH, getAbsoluteYPos() + HIGHSCORE_LIST_ENTRY_HEIGHT, al_map_rgb(255, 255, 120), 5);
	}
	result = entryName.draw();
	result &= entryPoints.draw();
	return result;
}


string HighScoreListEntry::getName(void) {
	return entryName.getName();
}

void HighScoreListEntry::setName(string newName) {
	entryName.setName(newName);
}


void HighScoreListEntry::setActive(bool active) {
	this->active = active;
}