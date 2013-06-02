#include "PlayingField.h"


PlayingField::PlayingField(int x, int y) {
	this->setRelativeCoord(new Coordinate(x, y));
	this->setParent(0);
	createBlockLines();
	createEventSource();
}


PlayingField::~PlayingField(void) {
	deleteBlockLines();
	al_destroy_user_event_source(getEventSource());
}

void PlayingField::draw(void) {
	for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
		getBlockLine(i)->draw();
	}
}

void PlayingField::createBlockLines(void) {
	for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
		createBlockLine(i);
	}
}

void PlayingField::createBlockLine(int index) {	
	BlockLine* line;
	line = new BlockLine(index);
	line->setParent(this);
	this->blockLines[index] = line;
}

void PlayingField::createEventSource(void) {
	al_init_user_event_source(getEventSource());
}

bool PlayingField::addBlockPart(BlockPart* part) {
	int col = part->getAbsoluteXPos() / BLOCK_WIDTH;
	int row = part->getAbsoluteYPos() / BLOCK_HEIGHT;
	return getBlockLine(row)->addBlockPart(col, part);
}

void PlayingField::deleteBlockLines(void) {
	for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
		delete this->blockLines[i];
	}
}

void PlayingField::removeCompleteLines(void) {
	list<BlockLine*> completeList;
	list<BlockLine*>::iterator it;
	BlockLine* line;
	int index, count;
	count = 0;
	for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
		line = getBlockLine(i);
		if (line->isComplete()) {
			completeList.push_back(line);
		}
	}
	for (it = completeList.begin(); it != completeList.end(); it++) {
		index = (*it)->getRelativeYPos() / BLOCK_HEIGHT;
		dropLinesBetweenIndices(count, index);
		delete *it;
		count++;
	}
	for (int i = 0; i < count; i++) {
		createBlockLine(i);
	}
	if (count > 0) {
		emitLineCompleteEvent(count);
	}
}

void PlayingField::emitLineCompleteEvent(int amountOfLines) {
	ALLEGRO_EVENT ev;
	ev.user.data1 = amountOfLines;
	ev.type = ALLEGRO_GET_EVENT_TYPE('l', 'i', 'n', 'e');
	al_emit_user_event(getEventSource(), &ev, 0);
}

void PlayingField::dropLinesBetweenIndices(int startIndex, int endIndex) {
	for (int i = endIndex - 1; i >= startIndex; i--) {
		dropLine(i);
	}
}

void PlayingField::dropLine(int index) {
	getBlockLine(index)->increaseY(BLOCK_WIDTH);
	this->setBlockLine(index + 1, getBlockLine(index));
}

bool PlayingField::isBlocked(int x, int y) {
	if (x >= GAME_FIELD_WIDTH * BLOCK_WIDTH 
		|| x < 0 || y >= GAME_FIELD_HEIGHT * BLOCK_HEIGHT || y < 0) {
		return true;
	} else if (getBlockPart(x, y) != 0) {
		return true;
	} else {
		return false;
	}
}

BlockPart* PlayingField::getBlockPart(int x, int y) {
	return getBlockLineByCoordinate(y)->getBlockPartByCoordinate(x);
}

ALLEGRO_EVENT_SOURCE* PlayingField::getEventSource(void) {
	return &(this->evSource);
}

BlockLine* PlayingField::getBlockLineByCoordinate(int y) {
	int row = y / BLOCK_HEIGHT;
	if (row >= 0 && row < GAME_FIELD_HEIGHT) {
		return getBlockLine(row);
	} else {
		return 0;
	}
}


bool PlayingField::isEmpty(int lineIndex) {
	return getBlockLine(lineIndex)->isEmpty();
}

BlockLine* PlayingField::getBlockLine(int index) {
	if (index >= 0 && index < GAME_FIELD_HEIGHT) {
		return this->blockLines[index];
	}
	return 0;
}


bool PlayingField::setBlockLine(int index, BlockLine* line) {
	if (index >= 0 && index < GAME_FIELD_HEIGHT) {
		this->blockLines[index] = line;
		return true;
	} else {
		return false;
	}
}