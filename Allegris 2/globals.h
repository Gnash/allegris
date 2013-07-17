#pragma once
#include <iostream>

using namespace std;

const int BITMAP_INDEX_BLOCK_BLUE = 0;
const int BITMAP_INDEX_BLOCK_CYAN = 1;
const int BITMAP_INDEX_BLOCK_GREEN = 2;
const int BITMAP_INDEX_BLOCK_MAGENTA = 3;
const int BITMAP_INDEX_BLOCK_ORANGE = 4;
const int BITMAP_INDEX_BLOCK_RED = 5;
const int BITMAP_INDEX_BLOCK_YELLOW = 6;
const int BITMAP_INDEX_BLOCK_PREVIEWWINDOW = 7;

const int FONT_INDEX_MAINMENU = 0;
const int FONT_INDEX_HIGHSCORE = 0;

const int BLOCK_WIDTH = 30;
const int BLOCK_HEIGHT = 30;

const int GAME_FIELD_WIDTH = 10;
const int GAME_FIELD_HEIGHT = 18;

const int HIGHSCORE_LIST_WIDTH = 300;
const int HIGHSCORE_LIST_ENTRY_HEIGHT = 40;
const int HIGHSCORE_LIST_NAME_WIDTH = HIGHSCORE_LIST_WIDTH / 2;
const int HIGHSCORE_LIST_LENGTH = 10;

const int INFO_WINDOW_X= GAME_FIELD_WIDTH * BLOCK_WIDTH;
const int INFO_WINDOW_Y = 0;

const int INFO_WINDOW_WIDTH = 200;

const int PREVIEW_WINDOW_WIDTH = 150;
const int PREVIEW_WINDOW_HEIGHT = 150;

const int DIRECTION_LEFT = 0;
const int DIRECTION_RIGHT = 1;
const int DIRECTION_DOWN = 2;
const int DIRECTION_UP = 3;

const int MENU_ITEM_HEIGHT = 50;

const int MENU_START = 0;
const int MENU_HIGHSCORE = 1;
const int MENU_END = 2;

const int SCREEN_WIDTH = GAME_FIELD_WIDTH * BLOCK_WIDTH + INFO_WINDOW_WIDTH;
const int SCREEN_HEIGHT = GAME_FIELD_HEIGHT * BLOCK_HEIGHT;

const int HIGHSCORE_MARGIN_LEFT = (SCREEN_WIDTH - HIGHSCORE_LIST_WIDTH) / 2;
const int HIGHSCORE_MARGIN_TOP = 100;

const int BASE_SPEED = 1;
const int DROP_SPEED = 20;
const int NAVIGATION_SPEED = 3;
const double SPEED_POTENCY_BASE = 1.2;

const int MOVE_OK = 0;
const int MOVE_BLOCKED = 1;
const int MOVE_STUCK = 2;
const int MOVE_ERROR = 3;

const int BLOCK_SPAWN_X = BLOCK_WIDTH * 4;
const int BLOCK_SPAWN_Y = 0;

const int LINES_FOR_LEVELUP = 10;

const int POINTS_AMOUNT_BASE = 2;
const int POINTS_LEVEL_BASE = 2;

const int RED = 0;
const int BLUE = 1;
const int GREEN = 2;
const int YELLOW = 3;
const int CYAN = 4;
const int MAGENTA = 5;