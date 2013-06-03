#include "MenuItemList.h"


MenuItemList::MenuItemList(void)
{
	this->setParent(0);
	this->setRelativeCoord(new Coordinate(50, 50));
	this->activeItemIndex = 0;
}


MenuItemList::~MenuItemList(void)
{
	vector<MenuItem*>::iterator it;
	it = menuItems.begin();
	for (it = menuItems.begin(); it != menuItems.end(); it++){
		delete *it;
	}
}

bool MenuItemList::draw(void) {
	vector<MenuItem*>::iterator it;
	it = menuItems.begin();
	for (it = menuItems.begin(); it != menuItems.end(); it++){
		if (!(*it)->draw()) {
			return false;
		}
	}
	return true;
}

void MenuItemList::addMenuItem(MenuItem* newItem) {
	menuItems.push_back(newItem);
	if (menuItems.size() == 1) {
		newItem->setActive(true);
	}
}

MenuItem* MenuItemList::getPreviousMenuItem(void) {
	int size = getMenuItems().size();
	if (size == 0) {
		return 0;
	} else {
		int newIndex = abs((getActiveItemIndex() - 1) % size);
		MenuItem* nextItem = getMenuItem(newIndex);
		getMenuItem(getActiveItemIndex())->setActive(false);
		nextItem->setActive(true);
		setActiveItemIndex(newIndex);
		return nextItem;
	}
}

MenuItem* MenuItemList::getNextMenuItem(void) {
	int size = getMenuItems().size();
	if (size == 0) {
		return 0;
	} else {
		int newIndex = (getActiveItemIndex() + 1) % size;
		MenuItem* nextItem = getMenuItem(newIndex);
		getMenuItem(getActiveItemIndex())->setActive(false);
		nextItem->setActive(true);
		setActiveItemIndex(newIndex);
		return nextItem;
	}
}

vector<MenuItem*> MenuItemList::getMenuItems(void) {
	return this->menuItems;
}

MenuItem* MenuItemList::getMenuItem(int index) {
	if (index < 0 || index >= getMenuItems().size()) {
		return 0;
	} else {
		return getMenuItems().at(index);
	}
}

int MenuItemList::getActiveItemIndex(void) {
	return this->activeItemIndex;
}

void MenuItemList::setActiveItemIndex(int index) {
	this->activeItemIndex = index;
}