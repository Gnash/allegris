#include "BlockPart.h"


BlockPart::BlockPart(int x, int y, int blockColor) {
	this->setRelativeCoord(new Coordinate(x, y));
	this->setParent(0);
	this->setGraphicsComponent(createBlockGraphics(blockColor));
}


BlockPart::~BlockPart(void) {
	delete graphics;
}


bool BlockPart::draw(void) {
	return graphics->draw();
}

int BlockPart::getXIndex(void) {
	return this->getRelativeCoordinate()->getX();
}

int BlockPart::getYIndex(void) {
	return this->getRelativeCoordinate()->getY();
}

int BlockPart::getRelativeXPos(void) {
	return this->getRelativeCoordinate()->getX() * BLOCK_WIDTH;
}

int BlockPart::getRelativeYPos(void) {
	return this->getRelativeCoordinate()->getY() * BLOCK_WIDTH;
}


void BlockPart::setGraphicsComponent(GraphicsComponent* graphics) {
	this->graphics = graphics;
}

GraphicsComponent* BlockPart::createBlockGraphics(int blockColor) {
	switch (blockColor) {
	case RED:
		return new BlockPartGraphics_Red(this);
	case BLUE:
		return new BlockPartGraphics_Blue(this);
	case YELLOW:
		return new BlockPartGraphics_Yellow(this);
	case GREEN:
		return new BlockPartGraphics_Green(this);
	case CYAN:
		return new BlockPartGraphics_Cyan(this);
	case MAGENTA:
		return new BlockPartGraphics_Magenta(this);
	}
	return 0;
}