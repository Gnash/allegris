#include "InfoField.h"
#include "allegro5\allegro_primitives.h"
#include "FontHandler.h"


InfoField::InfoField(int x, int y, int& level, int& points): previewWindow((INFO_WINDOW_WIDTH - PREVIEW_WINDOW_WIDTH) / 2, (INFO_WINDOW_WIDTH - PREVIEW_WINDOW_WIDTH) / 2)
{
	this->setRelativeCoord(new Coordinate(x, y));
	previewWindow.setParent(this);
	//TODO BLAAA
}


InfoField::~InfoField(void)
{
}


PreviewWindow& InfoField::getPreviewWindow(void) {
	return this->previewWindow;
}


bool InfoField::draw(void) {
	int x = getAbsoluteXPos();
	int y = getAbsoluteYPos();
	al_draw_filled_rectangle(x, y, x + INFO_WINDOW_WIDTH, y + SCREEN_HEIGHT, al_map_rgb(20, 0, 20));
	previewWindow.draw();
	return true;
}