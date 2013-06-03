#include "BlockLine.h"


BlockLine::BlockLine(int y) {
	this->setRelativeCoord(new Coordinate(0, y * BLOCK_HEIGHT));
	initializeBlockParts();
}


BlockLine::~BlockLine(void) {
	for (int i = 0; i < GAME_FIELD_WIDTH; i++) {
		if (getBlockPart(i)) {
			delete getBlockPart(i);
		}
	}
}

void BlockLine::draw(void) {
	for (int i = 0; i < GAME_FIELD_WIDTH; i++) {
		if (getBlockPart(i)) {
			getBlockPart(i)->draw();
		}
	}
}

bool BlockLine::addBlockPart(int index, BlockPart* part) {
	if (this->getBlockPart(index)) {
		return false;
	} else {
		setBlockPart(index, part);
		part->setParent(this);
		part->setRelativeCoordinate(index, 0);
		return true;
	}
}

void BlockLine::initializeBlockParts(void) {
	for (int i = 0; i < GAME_FIELD_WIDTH; i++) {
		this->blockParts.push_back(0);
	}
}

bool BlockLine::isComplete(void) {
	BlockPart* part;
	for (int i = 0; i < GAME_FIELD_WIDTH; i++) {
		part = getBlockPart(i);
		if (!part) {
			return false;
		}
	}
	return true;
}

bool BlockLine::isEmpty(void) {
	BlockPart* part;
	for (int i = 0; i < GAME_FIELD_WIDTH; i++) {
		part = getBlockPart(i);
		if (part) {
			return false;
		}
	}
	return true;
}

BlockPart* BlockLine::getBlockPart(int index) {
	return this->blockParts.at(index);
}

BlockPart* BlockLine::getBlockPartByCoordinate(int x) {
	if (x < GAME_FIELD_WIDTH * BLOCK_WIDTH && x >= 0) {
		if (!getBlockPart(x / BLOCK_WIDTH)) {
			return 0;
		}
		return this->getBlockPart(x / BLOCK_WIDTH);
	} else {
		return 0;
	}
}

bool BlockLine::setBlockPart(int index, BlockPart* part) {
	if (index < GAME_FIELD_WIDTH && index >= 0) {
		this->blockParts.at(index) = part;
		return true;
	} else {
		return false;
	}
}