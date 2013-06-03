#pragma once
#include "ObjectComponent.h"
#include "BitmapHandler.h"

class GraphicsComponent :
	public ObjectComponent
{
public:
	GraphicsComponent(void);
	virtual ~GraphicsComponent(void);

	virtual bool draw(void) = 0;
};

