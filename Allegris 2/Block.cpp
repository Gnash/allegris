#include "Block.h"


Block::Block(void) {

}

Block::~Block(void) {
}

bool Block::draw(void) {
	vector<BlockPart*>::iterator it;
	for (it = this->blockParts.begin(); it != this->blockParts.end(); it++){
		if (!(*it)->draw()) {
			return false;
		}
	}
	return true;
}

bool Block::rotate(int direction) {
	switch (direction) {
	case DIRECTION_LEFT:
		return rotateLeft();
		break;
	case DIRECTION_RIGHT:
		return rotateRight();
		break;
	}
	return false;
}

bool Block::rotateLeft(void) {
	vector<Coordinate*> newCoords;
	BlockPart* part;
	int oldX, oldY, newX, newY, absoluteNewX, absoluteNewY;
	bool blocked = false;
	for (int i = 0; i < getBlockPartAmount(); i++) {
		part = getBlockPart(i);
		oldX = part->getXIndex();
		oldY = part->getYIndex();
		newX = oldY;
		newY = getWidth() - 1 - oldX;
		absoluteNewX = getAbsoluteNewX(newX, part);
		absoluteNewY = getAbsoluteNewY(newY, part);
		if (getPlayingField()->isBlocked(absoluteNewX, absoluteNewY)) {
			blocked = true;
			break;
		}
		newCoords.push_back(new Coordinate(newX, newY));
	}
	if (!blocked) {
		Coordinate* coord;
		for (int i = 0; i < getBlockPartAmount(); i++) {
			coord = newCoords.at(i);
			getBlockPart(i)->setRelativeCoordinate(coord->getX(), coord->getY());
		}
		switchWidthAndHeight();
	}
	newCoords.clear();
	return !blocked;
}

int Block::getAbsoluteNewX(int newX, BlockPart* part) {
	int diffX = (newX - part->getXIndex()) * BLOCK_WIDTH;
	return part->getAbsoluteXPos() + diffX;
}

int Block::getAbsoluteNewY(int newY, BlockPart* part) {
	int diffY = (newY - part->getYIndex()) * BLOCK_HEIGHT;
	return part->getAbsoluteYPos() + diffY;
}

bool Block::rotateRight(void) {
	vector<Coordinate*> newCoords;
	BlockPart* part;
	int oldX, oldY, newX, newY, absoluteNewX, absoluteNewY;
	bool blocked = false;
	for (int i = 0; i < getBlockPartAmount(); i++) {
		part = getBlockPart(i);
		oldX = part->getXIndex();
		oldY = part->getYIndex();
		newX = getHeight() - 1 - oldY;
		newY = oldX;
		absoluteNewX = getAbsoluteNewX(newX, part);
		absoluteNewY = getAbsoluteNewY(newY, part);
		if (getPlayingField()->isBlocked(absoluteNewX, absoluteNewY)) {
			blocked = true;
			break;
		}
		newCoords.push_back(new Coordinate(newX, newY));
	}
	if (!blocked) {
		Coordinate* coord;
		for (int i = 0; i < getBlockPartAmount(); i++) {
			coord = newCoords.at(i);
			getBlockPart(i)->setRelativeCoordinate(coord->getX(), coord->getY());
		}
		switchWidthAndHeight();
	}
	newCoords.clear();
	return !blocked;
}

void Block::switchWidthAndHeight(void) {
	int temp = getWidth();
	setWidth(getHeight());
	setHeight(temp);
}

int Block::move(int direction) {
	int result = MOVE_OK;
	switch (direction) {
		case DIRECTION_LEFT:
			if (!moveLeft()) {
				return MOVE_BLOCKED;
			}
			break;
		case DIRECTION_RIGHT:
			if 
				(!moveRight()) {
				return MOVE_BLOCKED;
			}
			break;
		case DIRECTION_DOWN:
			 if (!moveDown()) {
				 result = MOVE_STUCK;
			 }
			break;
		default:
			result = MOVE_ERROR;
			break;
	}
	return result;
}

bool Block::moveLeft(void) {
	if (this->getRelativeXPos() == 0) {
		return false;
	} else {
		BlockPart* part;
		for (int i = 0; i < this->getBlockPartAmount(); i++) {
			part = getBlockPart(i);
			if (part) {
				if (getPlayingField()->isBlocked(part->getAbsoluteXPos() - BLOCK_WIDTH, part->getAbsoluteYPos())) {
					return false;
				}
			}
		}
	}
	this->decreaseX(BLOCK_WIDTH);
	return true;
}

bool Block::moveRight(void) {
	if (this->getRelativeXPos() == (GAME_FIELD_WIDTH - getWidth()) * BLOCK_WIDTH) {
		return false;
	}else {
		BlockPart* part;
		for (int i = 0; i < this->getBlockPartAmount(); i++) {
			part = getBlockPart(i);
			if (part) {
				if (getPlayingField()->isBlocked(part->getAbsoluteXPos() + BLOCK_WIDTH, part->getAbsoluteYPos())) {
					return false;
				}
			}
		}
	}
	this->increaseX(BLOCK_WIDTH);
	return true;
}

bool Block::moveDown(void) {
	if (this->getRelativeYPos() == (GAME_FIELD_HEIGHT - getHeight()) * BLOCK_HEIGHT) {
		return false;
	} else {
		BlockPart* part;
		for (int i = 0; i < this->getBlockPartAmount(); i++) {
			part = getBlockPart(i);
			if (part) {
				if (getPlayingField()->isBlocked(part->getAbsoluteXPos(), part->getAbsoluteYPos() + BLOCK_HEIGHT)) {
					return false;
				}
			}
		}
	}
	this->increaseY(BLOCK_HEIGHT);
	return true;
}

bool Block::addBlockPart(BlockPart *part) {
	vector<BlockPart*>::iterator it;
	for (it = this->blockParts.begin(); it != this->blockParts.end(); it++){
		if ((*it)->getRelativeXPos() == part->getRelativeXPos() && 
			(*it)->getRelativeYPos() == part->getRelativeYPos()) {
			return false;
		}
	}
	this->blockParts.push_back(part);
	return true;
}


void Block::deleteBlockParts(void) {
	this->blockParts.clear();
}

int Block::getWidth(void) {
	return this->width;
}

int Block::getHeight(void) {
	return this->height;
}

PlayingField* Block::getPlayingField(void) {
	return this->playingField;
}

int Block::getBlockPartAmount(void) {
	return this->blockParts.size();
}

BlockPart* Block::getBlockPart(int index) {
	return this->blockParts.at(index);
}

int Block::getColor() {
	return this->color;
}

void Block::setColor(int color) {
	this->color = color;
}

void Block::setWidth(int w) {
	this->width = w;
}

void Block::setHeight(int h) {
	this->height = h;
}

void Block::setPlayingField(PlayingField* field) {
	this->playingField = field;
}

void Block::moveBlocksToPlayingField(void) {
	for (int i = 0; i < getBlockPartAmount(); i++) {
		getPlayingField()->addBlockPart(getBlockPart(i));
		setBlockPart(i, 0);
	}
}

void Block::setBlockPart(int index, BlockPart* part) {
	this->blockParts.at(index) = part;
}