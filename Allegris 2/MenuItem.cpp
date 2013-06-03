#include "MenuItem.h"


MenuItem::MenuItem(void)
{
}

MenuItem::MenuItem(GameObject* parentList, string text, int index) {
	this->text = text;
	this-> index = index;
	this->active = false;
	setParent(parentList);
	setRelativeCoord(new Coordinate(0, index * MENU_ITEM_HEIGHT));
	font = FontHandler::getFont(FONT_INDEX_MAINMENU);
}

MenuItem::~MenuItem(void)
{
	al_destroy_font(font);
}


bool MenuItem::draw(void)
{
	string text = "";
	if (isActive()) {
		text += std::string("> ");
		text += getText();
		text += " <";
	} else {
		text = getText();
	}
	al_draw_text(font, al_map_rgb(0, 255, 0), SCREEN_WIDTH / 2, getAbsoluteYPos(), ALLEGRO_ALIGN_CENTRE, text.c_str());
	return true;
}

int MenuItem::getIndex(void) {
	return this->index;
}

void MenuItem::setIndex(int index) {
	this->index = index;
}

string MenuItem::getText(void) {
	return this->text;
}

void MenuItem::setText(string text) {
	this->text = text;
}

bool MenuItem::isActive(void) {
	return this->active;
}

void MenuItem::setActive(bool active) {
	this->active = active;
}