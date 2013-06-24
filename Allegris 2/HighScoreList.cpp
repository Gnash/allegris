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


int HighScoreList::size(void) {
	return listEntries.size();
}

HighScoreListEntry* HighScoreList::getEntry(int index) {
	if (index >= 0 && index < listEntries.size()) {
		return listEntries.at(index);
	} else {
		return 0;
	}
}

HighScoreListEntry* HighScoreList::addEntry(string name, int points) {
	HighScoreListEntry* entry = (new HighScoreListEntry(0, listEntries.size() * HIGHSCORE_LIST_ENTRY_HEIGHT, HIGHSCORE_LIST_WIDTH, name, points));
	vector<HighScoreListEntry*>::iterator it(listEntries.begin());
	HighScoreListEntry* result = 0;
	entry->setParent(this);

	if (listEntries.size() == 0) {
		listEntries.push_back(entry);
		result = entry;
	} else if (listEntries.size() == 1) {
		if (listEntries.at(0) != 0 && points < listEntries.at(0)->getPoints()) {
			listEntries.push_back(entry);
		} else {
			listEntries.insert(listEntries.begin(), entry);
		}		
		result = entry;
	} else if (points > (*it)->getPoints()) {
		listEntries.insert(it, entry);
		if (listEntries.size() > HIGHSCORE_LIST_LENGTH) {
			listEntries.pop_back();
		}
		result = entry;
	} else {
		it = this->listEntries.begin();
		for (it = this->listEntries.begin(); it != this->listEntries.end() - 1; it++){
			if (points < (*it)->getPoints() && points >= (*(it+1))->getPoints()) {
				listEntries.insert(it + 1, entry);
				if (listEntries.size() > HIGHSCORE_LIST_LENGTH) {
					listEntries.pop_back();
				}
				result = entry;
			}
		}
		if (points < (*it)->getPoints() && listEntries.size() < HIGHSCORE_LIST_LENGTH) {
			listEntries.push_back(entry);
			result = entry;
		}
	}

	for (int i = 0; i < listEntries.size(); i++) {
		listEntries.at(i)->setRelativeCoordinate(0, i * HIGHSCORE_LIST_ENTRY_HEIGHT);
	}

	return result;
}