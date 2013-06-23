#include "HighScoreList.h"


HighScoreList::HighScoreList(void)
{
}


HighScoreList::~HighScoreList(void)
{
}

bool HighScoreList::draw(void) {
	vector<HighScoreListEntry>::iterator it(listEntries.begin());
	for (it = this->listEntries.begin(); it != this->listEntries.end(); it++){
		if (!(*it).draw()) {
			return false;
		}
	}
	return true;
}

void HighScoreList::addEntry(string name, int points) {
	HighScoreListEntry* entry = (new HighScoreListEntry(0, listEntries.size() * 40, name, points));
	entry->setParent(this);
	listEntries.push_back(*entry);
}