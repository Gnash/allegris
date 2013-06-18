#include "GameWindow.h"


GameWindow::GameWindow(void) : points(0) {
	this->completedLines = 0;
	this->activeBlock = 0;
	this->level = 1;
	this->blockMovesPerSecond = 1;
	this->playingField = new PlayingField(0, 0);
	this->previewWindow = new PreviewWindow(PREVIEW_WINDOW_X, PREVIEW_WINDOW_Y);
	this->blockMovingDown = false;
	this->blockFactory = new BlockFactory();
	createNewBlock();
	createNewBlockTimer();
	setBlockInputTimer(al_create_timer(1.0 / DROP_SPEED));
	al_register_event_source(getEventQueue(), getPlayingField()->getEventSource());
	al_register_event_source(getEventQueue(), al_get_timer_event_source(getBlockDropTimer()));
	al_register_event_source(getEventQueue(), al_get_timer_event_source(getBlockInputTimer()));
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
}


GameWindow::~GameWindow(void) {
	delete this->activeBlock;
	delete this->playingField;
	delete this->previewWindow;
	al_destroy_timer(getBlockDropTimer());
}


bool GameWindow::updateGraphic(void) {
	getPlayingField()->draw();
	return (this->activeBlock->draw() && previewWindow->draw());
}

bool GameWindow::updateLogic(void) {
	ALLEGRO_EVENT ev;
	while (!al_event_queue_is_empty(getEventQueue())) {
		al_wait_for_event(getEventQueue(), &ev);
		if (ev.type == ALLEGRO_GET_EVENT_TYPE('l', 'i', 'n', 'e')) {
			increaseCompletedLines(ev.user.data1);
		} else if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (ev.any.source == al_get_timer_event_source(getBlockDropTimer()) && 
				!isBlockMovingDown()) {
				dropBlock();
			} else if (ev.any.source == al_get_timer_event_source(getBlockInputTimer())) {			
				dropBlock();
			}
		} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			setBlockMovingDown(true);
			dropBlock();
			al_start_timer(getBlockInputTimer());
		} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_X) {
			getActiveBlock()->rotate(DIRECTION_RIGHT);
		} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_Y) {
			getActiveBlock()->rotate(DIRECTION_LEFT);
		} else if (ev.type == ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			al_stop_timer(getBlockInputTimer());
			setBlockMovingDown(false);
		} else if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				getActiveBlock()->move(DIRECTION_LEFT);
				break;
			case ALLEGRO_KEY_RIGHT:
				getActiveBlock()->move(DIRECTION_RIGHT);
				break;
			}
		}
	}
	return true;
}

void GameWindow::createNewBlock(void) {
	if (isSpawnBlocked()) {
		emitGameLostEvent();
	}
	if (this->activeBlock) {
		delete this->activeBlock;
	}
	if (getPreviewWindow()->getNextBlock()) {
		this->activeBlock = getPreviewWindow()->getNextBlock();
		this->activeBlock->setParent(getPlayingField());
		this->activeBlock->setRelativeCoordinate(BLOCK_SPAWN_X, BLOCK_SPAWN_Y);

	} else {
		this->activeBlock = blockFactory->createRandomBlock();
	}
	Block* nextBlock = blockFactory->createRandomBlock();
	nextBlock->setParent(previewWindow);
	nextBlock->setRelativeCoordinate(floor((PREVIEW_WINDOW_WIDTH - nextBlock->getWidth() * BLOCK_WIDTH) / 2), floor(((PREVIEW_WINDOW_HEIGHT - nextBlock->getHeight() * BLOCK_HEIGHT) / 2)));
	int bla = nextBlock->getAbsoluteXPos();
	int blubb = nextBlock->getAbsoluteYPos();
	getPreviewWindow()->setNextBlock(nextBlock);
	this->activeBlock->setPlayingField(getPlayingField());
}

void GameWindow::emitGameLostEvent(void) {
	ALLEGRO_EVENT ev;
	ev.user.data1 = getPoints();
	ev.type = ALLEGRO_GET_EVENT_TYPE('l', 'o', 's', 't');
	al_emit_user_event(getEventSource(), &ev, 0);
}

void GameWindow::dropBlock(void) {
	if (getActiveBlock()->move(DIRECTION_DOWN) == MOVE_STUCK) {
		getActiveBlock()->moveBlocksToPlayingField();
		getPlayingField()->removeCompleteLines();
		createNewBlock();
	}
}

void GameWindow::createNewBlockTimer(void) {
	if (this->blockDropTimer) {
		al_unregister_event_source(getEventQueue(), al_get_timer_event_source(getBlockDropTimer()));
	}
	this->blockDropTimer = al_create_timer(1.0 / getBlockMovesPerSecond());
	al_start_timer(getBlockDropTimer());
	al_register_event_source(getEventQueue(), al_get_timer_event_source(getBlockDropTimer()));
}

int GameWindow::getCurrentLevel(void) {
	return this->level;
}

int GameWindow::getBlockMovesPerSecond(void) {
	return BASE_SPEED * pow(SPEED_POTENCY_BASE, getCurrentLevel());
}

int GameWindow::getCurrentDirection(void) {
	return currentDirection;
}

Block* GameWindow::getActiveBlock(void) {
	return this->activeBlock;
}

ALLEGRO_TIMER* GameWindow::getBlockDropTimer(void) {
	return this->blockDropTimer;
}

ALLEGRO_TIMER* GameWindow::getBlockInputTimer(void) {
	return this->blockInputTimer;
}

PlayingField* GameWindow::getPlayingField(void) {
	return this->playingField;
}

bool GameWindow::isBlockMovingDown(void) {
	return this->blockMovingDown;
}

void GameWindow::setBlockInputTimer(ALLEGRO_TIMER *timer) {
	al_unregister_event_source(getEventQueue(), al_get_timer_event_source(getBlockInputTimer()));
	this->blockInputTimer = timer;
	al_register_event_source(getEventQueue(), al_get_timer_event_source(getBlockInputTimer()));
}

void GameWindow::setBlockMovingDown(bool moving) {
	this->blockMovingDown = moving;
}

void GameWindow::increaseCompletedLines(int amount) {
	increasePoints(amount, getCurrentLevel());
	this->completedLines += amount;
	while (this->completedLines >= LINES_FOR_LEVELUP) {
		increaseLevel();
		this->completedLines -= LINES_FOR_LEVELUP;
	}
	cout << "Lines: " << this->completedLines << endl;
}

void GameWindow::increasePoints(int amount, int currentLevel) {
	this->points = points + pow(POINTS_AMOUNT_BASE, amount) * pow(POINTS_LEVEL_BASE, currentLevel);
}

void GameWindow::increaseLevel(void) {
	this->level++;
	cout << "New level: " << this->level << endl;
	createNewBlockTimer();
}

PreviewWindow* GameWindow::getPreviewWindow(void) {
	return this->previewWindow;
}

bool GameWindow::isSpawnBlocked(void) {
	return getPlayingField()->isBlocked(BLOCK_SPAWN_X, 0);
}

int GameWindow::getPoints(void) {
	return this->points;
}