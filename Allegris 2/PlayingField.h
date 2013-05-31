#pragma once
#include "gameobject.h"
#include "BlockLine.h"
#include <list>

class PlayingField :
	public GameObject
{
public:
	PlayingField(int x, int y);
	~PlayingField(void);

	void draw(void);
	bool addBlockPart(BlockPart* part);
	void removeCompleteLines(void);
	
	bool isEmpty(int lineIndex);
	bool isBlocked(int x, int y);
	BlockLine* getBlockLine(int index);
	BlockLine* getBlockLineByCoordinate(int y);
	BlockPart* getBlockPart(int x, int y);
	ALLEGRO_EVENT_SOURCE* getEventSource(void);
	bool setBlockLine(int index, BlockLine* part);

private:
	void createBlockLines(void);
	void deleteBlockLines(void);
	void createBlockLine(int index);
	void createEventSource(void);
	void dropLinesBetweenIndices(int startIndex, int endIndex);
	void dropLine(int index);

	BlockLine* blockLines[GAME_FIELD_HEIGHT];
	ALLEGRO_EVENT_SOURCE evSource;
};

