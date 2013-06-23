#include "HighScoreList.h"
#include "HighScoreListEntry.h"


HighScoreList::HighScoreList(int x, int y)
{
	setRelativeCoord(new Coordinate(x, y));
}


HighScoreList::~HighScoreList(void)
{
}

bool HighScoreList::draw(void) {
	vector<HighScoreListEntry*>::iterator it(listEntries.begin());
	for (it = this->listEntries.begin(); it != this->listEntries.end(); it++){
		if (!(*it)->draw()) {
			return false;
		}
	}
	return true;
}

HighScoreListEntry* HighScoreList::addEntry(string name, int points) {
	HighScoreListEntry* entry = (new HighScoreListEntry(0, listEntries.size() * HIGHSCORE_LIST_ENTRY_HEIGHT, HIGHSCORE_LIST_WIDTH, name, points));
	entry->setParent(this);
	listEntries.push_back(entry);
	return entry;
}