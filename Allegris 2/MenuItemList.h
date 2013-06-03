#pragma once
#include "gameobject.h"
#include "MenuItem.h"
#include <vector>
class MenuItemList :
	public GameObject
{
public:
	MenuItemList(void);
	~MenuItemList(void);

	bool draw(void);
	MenuItem* getNextMenuItem(void);
	MenuItem* getPreviousMenuItem(void);
	void addMenuItem(MenuItem* newItem);
	int getActiveItemIndex(void);
private:
	vector<MenuItem*> getMenuItems(void);
	MenuItem* getMenuItem(int index);
	void setActiveItemIndex(int index);

	vector<MenuItem*> menuItems;
	int activeItemIndex;
};

