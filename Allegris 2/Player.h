#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player(string name);
	~Player(void);

	void setName(string name);
private:
	string name;
};

