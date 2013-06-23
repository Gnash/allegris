#include "HighScore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int HIGHSCORE_MAX_NAME_LENGTH = 10;

std::vector<std::string> explode(std::string const & s, char delim);

HighScore::HighScore(int points) : inputMode(true), underscoreVisible(false), highScoreList(loadHighScoreList("highscore.txt")) {
	underscoreTimer = al_create_timer(0.5);
	al_register_event_source(getEventQueue(), al_get_timer_event_source(underscoreTimer));
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
	newHighScore = highScoreList.addEntry("", points);
	al_start_timer(underscoreTimer);
}

HighScore::~HighScore(void)
{
	al_destroy_timer(underscoreTimer);
}


bool HighScore::updateGraphic(void) {
	al_clear_to_color(al_map_rgb(10, 0, 0));
	getHighScoreList().draw();
	return true;
}

bool HighScore::updateLogic(void) {
	if (this->inputMode) {
		ALLEGRO_EVENT ev;
		string name = newHighScore->getName();
		while (!al_event_queue_is_empty(getEventQueue())) {
			al_wait_for_event(getEventQueue(), &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER) {
				if (ev.any.source == al_get_timer_event_source(underscoreTimer)) {
					setUnderscoreVisibility(!underscoreVisible, name);
				}
			}

			if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
				switch (ev.keyboard.keycode) {
					case ALLEGRO_KEY_BACKSPACE:
						name.pop_back();
						break;
					case ALLEGRO_KEY_ENTER:
						disableInput(name);
						break;
					default:
						handleNameInput(ev.keyboard.unichar, name);
						break;
				}
			}
		newHighScore->setName(name);
		}
	}
	return true;
}

HighScoreList& HighScore::getHighScoreList(void) {
	return this->highScoreList;
}


void HighScore::disableInput(string &name) {
	inputMode = false;
	setUnderscoreVisibility(false, name);
	al_stop_timer(underscoreTimer);
}

void HighScore::handleNameInput(int inputUnicode, string &name) {
	if (inputUnicode >= 32 && name.size() < HIGHSCORE_MAX_NAME_LENGTH) {
		if (underscoreVisible) {
			name.pop_back();
			name += char(inputUnicode);
			name += "_";
		} else {	
			name += char(inputUnicode);
		}
	}
}

void HighScore::setUnderscoreVisibility(bool visibility, string &name) {
	this->underscoreVisible = visibility;
	if (underscoreVisible) {
		name += "_";
		HIGHSCORE_MAX_NAME_LENGTH++;
	} else {
		name.pop_back();
		HIGHSCORE_MAX_NAME_LENGTH--;
	}
}


HighScoreList HighScore::loadHighScoreList(string filePath) {
	HighScoreList result = HighScoreList(HIGHSCORE_MARGIN_LEFT, HIGHSCORE_MARGIN_TOP);
	ifstream highScoreFile;
	highScoreFile.open(filePath);
	if (highScoreFile.is_open()) {
		string line;
		string name;
		int size = 0;
		int points = 0;
		while (highScoreFile.good() && size < 10) {
			getline(highScoreFile, line);
			vector<string> entry = explode(line, ';');
			if (entry.size() == 2) {
				if (entry.at(0).length() > 10) {
					name = entry.at(0).substr(0, 10);
				} else {
					name = entry.at(0);
				}
				stringstream ss(entry.at(1));
				ss >> points;
				result.addEntry(name, points);
			}
		}
	}
	return result;
}

std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}