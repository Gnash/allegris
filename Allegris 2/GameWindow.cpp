#include "GameWindow.h"


GameWindow::GameWindow(void) {
	this->completedLines = 0;
	this->activeBlock = 0;
	this->level = 1;
	this->blockMovesPerSecond = 1;
	this->evQueue = al_create_event_queue();
	this->playingField = new PlayingField(0, 0);
	this->blockMovingDown = false;
	this->blockFactory = new BlockFactory();
	createNewBlock();
	createNewBlockTimer();
	setBlockInputTimer(al_create_timer(1.0 / DROP_SPEED));
	al_register_event_source(evQueue, getPlayingField()->getEventSource());
	al_register_event_source(evQueue, al_get_timer_event_source(getBlockDropTimer()));
	al_register_event_source(evQueue, al_get_timer_event_source(getBlockInputTimer()));
	al_register_event_source(evQueue, al_get_keyboard_event_source());
}


GameWindow::~GameWindow(void) {
	delete this->activeBlock;
	delete this->playingField;
	al_destroy_event_queue(evQueue);
	al_destroy_timer(getBlockDropTimer());
}


bool GameWindow::updateGraphic(void) {
	getPlayingField()->draw();
	return this->activeBlock->draw();
}

bool GameWindow::updateLogic(void) {
	ALLEGRO_EVENT ev;
	while (!al_event_queue_is_empty(evQueue)) {
		al_wait_for_event(evQueue, &ev);
		if (ev.type == ALLEGRO_GET_EVENT_TYPE('l', 'i', 'n', 'e')) {
			increaseCompletedLines(ev.user.data1);
		}
		if (ev.type == ALLEGRO_EVENT_TIMER) {
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
	if (this->activeBlock) {
		delete this->activeBlock;
	}
	this->activeBlock = blockFactory->createRandomBlock();
	this->activeBlock->setPlayingField(getPlayingField());
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

ALLEGRO_EVENT_QUEUE* GameWindow::getEventQueue(void) {
	return this->evQueue;
}

bool GameWindow::isBlockMovingDown(void) {
	return this->blockMovingDown;
}

void GameWindow::setBlockInputTimer(ALLEGRO_TIMER *timer) {
	al_unregister_event_source(evQueue, al_get_timer_event_source(getBlockInputTimer()));
	this->blockInputTimer = timer;
	al_register_event_source(evQueue, al_get_timer_event_source(getBlockInputTimer()));
}

void GameWindow::setBlockMovingDown(bool moving) {
	this->blockMovingDown = moving;
}

void GameWindow::increaseCompletedLines(int amount) {
	this->completedLines += amount;
	while (this->completedLines >= LINES_FOR_LEVELUP) {
		increaseLevel();
		this->completedLines -= LINES_FOR_LEVELUP;
	}
	cout << "Lines: " << this->completedLines << endl;
}

void GameWindow::increaseLevel(void) {
	this->level++;
	cout << "New level: " << this->level << endl;
	createNewBlockTimer();
}