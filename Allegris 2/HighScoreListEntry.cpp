#include "HighScoreListEntry.h"


HighScoreListEntry::HighScoreListEntry(int x, int y, string name, int points) 
		: entryName(x, y, name), entryPoints(x + HIGHSCORE_LIST_NAME_WIDTH, y, points) {
	entryName.setParent(this);
	entryPoints.setParent(this);
	this->setRelativeCoord(new Coordinate(x, y));
	
}


HighScoreListEntry::~HighScoreListEntry(void)
{
}


bool HighScoreListEntry::draw(void) {
	bool result = true;
	result = entryName.draw();
	result &= entryPoints.draw();
	return result;
}

