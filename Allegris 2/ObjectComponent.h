#pragma once
#include "GameObject.h"

class ObjectComponent
{
public:
	ObjectComponent(void);
	virtual ~ObjectComponent(void);

	GameObject* getObject(void);
protected:
	GameObject* object;
};

