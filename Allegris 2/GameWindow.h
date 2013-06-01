#pragma once
#include "gamestate.h"
#include "Block.h"
#include "BlockFactory.h"
#include "BlockLine.h"
#include "PlayingField.h"
#include "globals.h"
#include "PreviewWindow.h"
#include <allegro5/allegro.h>


class GameWindow :
	public GameState, GameObject
{
public:
	GameWindow(void);
	~GameWindow(void);

	bool updateLogic(void);
	bool updateGraphic(void);

private:
	void createNewBlockTimer(void);
	void createNewBlock(void);
	void dropBlock(void);
	
	Block* getActiveBlock(void);
	int getCurrentLevel(void);
	int getCompletedLines(void);
	int getCurrentDirection(void);
	int getBlockMovesPerSecond(void);
	PreviewWindow* getPreviewWindow(void);
	ALLEGRO_EVENT_QUEUE* getEventQueue(void);
	ALLEGRO_TIMER* getBlockDropTimer(void);
	ALLEGRO_TIMER* getBlockInputTimer(void);
	PlayingField* getPlayingField(void);
	bool isBlockMovingDown(void);
	void setBlockInputTimer(ALLEGRO_TIMER *timer);
	void setBlockMovingDown(bool moving);
	void increaseCompletedLines(int amount);
	void increaseLevel(void);

	Block* activeBlock;
	BlockFactory* blockFactory;
	PlayingField* playingField;
	PreviewWindow* previewWindow;
	ALLEGRO_EVENT_QUEUE *evQueue;
	ALLEGRO_TIMER *blockDropTimer;
	ALLEGRO_TIMER *blockInputTimer;
	
	int level;
	int completedLines;
	int currentDirection;
	int blockMovesPerSecond;
	int dropMovesPerSecond;
	int sidewardsMovesPerSecond;
	bool blockMovingDown;
};

