#include "PreviewWindow.h"
#include <allegro5/allegro_primitives.h>

PreviewWindow::PreviewWindow(int x, int y)
{
	this->setRelativeCoord(new Coordinate(x, y));
	this->nextBlock = 0;
	this->setParent(0);
}


PreviewWindow::~PreviewWindow(void)
{
	delete this->nextBlock;
}


void PreviewWindow::setNextBlock(Block* nextBlock) {
	this->nextBlock = nextBlock;
}

Block* PreviewWindow::getNextBlock(void) {
	return this->nextBlock;
}

bool PreviewWindow::draw(void) {
	bool success = true;
	int x = getAbsoluteXPos();
	int y = getAbsoluteYPos();
	al_draw_rectangle(x, y, x + PREVIEW_WINDOW_WIDTH, y + PREVIEW_WINDOW_WIDTH, al_map_rgb(0, 255, 0), 3);
	if (getNextBlock()) {
		success = success && getNextBlock()->draw();
	}
	return success;
}