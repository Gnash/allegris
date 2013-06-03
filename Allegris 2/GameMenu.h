#pragma once
#include "GameState.h"
#include "MenuItemList.h"
class GameMenu:
	public GameState
{
public:
	GameMenu(void);
	~GameMenu(void);

	bool updateLogic(void);
	bool updateGraphic(void);

private:
	void emitGameStartEvent(void);
	void emitCloseEvent(void);
	void selectMenuItem(void);
	MenuItemList* getMenuItemList(void);
	MenuItemList* menuItemList;
};

