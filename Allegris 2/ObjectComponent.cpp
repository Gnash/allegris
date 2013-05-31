#include "ObjectComponent.h"


ObjectComponent::ObjectComponent(void)
{
}


ObjectComponent::~ObjectComponent(void)
{
}

GameObject* ObjectComponent::getObject(void) {
	return this->object;
}
