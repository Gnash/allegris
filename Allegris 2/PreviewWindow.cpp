#include "PreviewWindow.h"


PreviewWindow::PreviewWindow(int x, int y)
{
	this->setRelativeCoord(new Coordinate(x, y));
	this->nextBlock = 0;
	this->setParent(0);
	this->graphics = new PreviewWindowGraphics(this);
}


PreviewWindow::~PreviewWindow(void)
{
	delete this->nextBlock;
	delete this->graphics;
}


void PreviewWindow::setNextBlock(Block* nextBlock) {
	this->nextBlock = nextBlock;
}

Block* PreviewWindow::getNextBlock(void) {
	return this->nextBlock;
}

bool PreviewWindow::draw(void) {
	return graphics->draw();
}