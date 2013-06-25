#include "GameMenu.h"


GameMenu::GameMenu(void)
{
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
	this->menuItemList = new MenuItemList();
	getMenuItemList()->addMenuItem(new MenuItem(getMenuItemList(), "Spiel starten", 0));
	getMenuItemList()->addMenuItem(new MenuItem(getMenuItemList(), "Bestenliste", 1));
	getMenuItemList()->addMenuItem(new MenuItem(getMenuItemList(), "Beenden", 2));
}


GameMenu::~GameMenu(void)
{
}


bool GameMenu::updateGraphic(void) {
	al_clear_to_color(al_map_rgb(50, 50, 50));
	getMenuItemList()->draw();
	return true;
}

bool GameMenu::updateLogic(void) {
	ALLEGRO_EVENT ev;
	while (!al_event_queue_is_empty(getEventQueue())) {
		al_wait_for_event(getEventQueue(), &ev);
		
		if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				getMenuItemList()->getPreviousMenuItem();
				break;
			case ALLEGRO_KEY_DOWN:
				getMenuItemList()->getNextMenuItem();
				break;
			case ALLEGRO_KEY_ENTER:
				selectMenuItem();
			}

		}
	}
	return true;
}

void GameMenu::selectMenuItem(void) {
	switch (getMenuItemList()->getActiveItemIndex()) {
	case MENU_START:
		emitGameStartEvent();
		break;
	case MENU_HIGHSCORE:
		emitHighScoreEvent();
		break;
	case MENU_END:
		emitCloseEvent();
		break;
	}
}

void GameMenu::emitHighScoreEvent(void) {
	ALLEGRO_EVENT ev;
	ev.type = ALLEGRO_GET_EVENT_TYPE('h', 'i', 'g', 'h');
	al_emit_user_event(getEventSource(), &ev, 0);
}

void GameMenu::emitGameStartEvent(void) {
	ALLEGRO_EVENT ev;
	ev.type = ALLEGRO_GET_EVENT_TYPE('s', 't', 'r', 't');
	al_emit_user_event(getEventSource(), &ev, 0);
}

void GameMenu::emitCloseEvent(void) {
	ALLEGRO_EVENT ev;
	ev.type = ALLEGRO_GET_EVENT_TYPE('c', 'l', 'o', 's');
	al_emit_user_event(getEventSource(), &ev, 0);
}

MenuItemList* GameMenu::getMenuItemList(void) {
	return this->menuItemList;
}