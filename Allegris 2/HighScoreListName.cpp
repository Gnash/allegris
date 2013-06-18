#include "HighScoreListName.h"


HighScoreListName::HighScoreListName(int x, int y, string name): name(name)
{
	setRelativeCoord(new Coordinate(x, y));
}


HighScoreListName::~HighScoreListName(void)
{
}


bool HighScoreListName::draw(void) {
	return true;
}