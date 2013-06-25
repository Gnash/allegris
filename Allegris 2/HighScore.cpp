#include "HighScore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>

int HIGHSCORE_MAX_NAME_LENGTH = 10;

const string RETURN_TEXT = ">>Zurueck zum Menue<<";

std::vector<std::string> explode(std::string const & s, char delim);


HighScore::HighScore(void) : inputMode(false), underscoreVisible(false), highScoreList(HIGHSCORE_MARGIN_LEFT, HIGHSCORE_MARGIN_TOP), font(FontHandler::getFont(FONT_INDEX_HIGHSCORE)) {
	loadHighScoreList(highScoreList, "highscore.txt");
	underscoreTimer = al_create_timer(0.5);
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
}

HighScore::HighScore(int points) : inputMode(true), underscoreVisible(false), highScoreList(HIGHSCORE_MARGIN_LEFT, HIGHSCORE_MARGIN_TOP), font(FontHandler::getFont(FONT_INDEX_HIGHSCORE)) {
	loadHighScoreList(highScoreList, "highscore.txt");
	underscoreTimer = al_create_timer(0.5);
	al_register_event_source(getEventQueue(), al_get_timer_event_source(underscoreTimer));
	al_register_event_source(getEventQueue(), al_get_keyboard_event_source());
	newHighScore = highScoreList.addEntry("", points);
	if (newHighScore == 0) {
		inputMode = false;
	} else {
		al_start_timer(underscoreTimer);
	}
}

HighScore::~HighScore(void)
{
	al_destroy_timer(underscoreTimer);
}


bool HighScore::updateGraphic(void) {
	al_clear_to_color(al_map_rgb(10, 0, 0));
	getHighScoreList().draw();
	if (!inputMode) {
		al_draw_text(this->font, al_map_rgb(0, 0, 200), SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, ALLEGRO_ALIGN_CENTRE, RETURN_TEXT.c_str());
	}
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
						if (underscoreVisible && name.size() > 1) {
							name.pop_back();
							name.pop_back();
							name += "_";
						} else if (!underscoreVisible && name.size() > 0) {
							name.pop_back();
						}
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
	} else {
		ALLEGRO_EVENT ev;
		while (!al_event_queue_is_empty(getEventQueue())) {
			al_wait_for_event(getEventQueue(), &ev);

			if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
				switch (ev.keyboard.keycode) {
				
					case ALLEGRO_KEY_ENTER:
						emitMainMenuEvent();
						break;
				}
			}
		}
	}
	return true;
}


void HighScore::emitMainMenuEvent(void) {
	ALLEGRO_EVENT ev;
	ev.type = ALLEGRO_GET_EVENT_TYPE('m', 'e', 'n', 'u');
	al_emit_user_event(getEventSource(), &ev, 0);
}

HighScoreList& HighScore::getHighScoreList(void) {
	return this->highScoreList;
}


void HighScore::disableInput(string &name) {
	inputMode = false;
	setUnderscoreVisibility(false, name);
	al_stop_timer(underscoreTimer);
	saveHighScoreList(highScoreList, "highscore.txt");
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
	if (!underscoreVisible && visibility) {
		name += "_";
		HIGHSCORE_MAX_NAME_LENGTH++;
	} else if (underscoreVisible && !visibility) {
		name.pop_back();
		HIGHSCORE_MAX_NAME_LENGTH--;
	}
	
	this->underscoreVisible = visibility;
}


void HighScore::loadHighScoreList(HighScoreList& list, string filePath) {
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
				list.addEntry(name, points);
			}
		}
	}
	highScoreFile.close();
}

void HighScore::saveHighScoreList(HighScoreList& list, string filePath) {
	ofstream highScoreFile(filePath);
	for (int i = 0; i < list.size(); i++) {
		HighScoreListEntry* entry = list.getEntry(i);
		if (entry != 0) {
			highScoreFile << entry->getName() << ";" << entry->getPoints() << endl;
		}
	}
	highScoreFile.close();
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