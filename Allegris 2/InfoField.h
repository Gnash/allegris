#pragma once
#include "gameobject.h"
#include "PreviewWindow.h"
#include "InfoBox.h"
class InfoField :
	public GameObject
{
public:
	InfoField(int x, int y, int& currentLevel, int& currentPoints);
	~InfoField(void);
	PreviewWindow& getPreviewWindow(void);
	bool draw(void);

private:
	PreviewWindow previewWindow;
	InfoBox currentPoints;
	InfoBox currentLevel;
	int& currentLevel;
	int& currentPoints;
};

