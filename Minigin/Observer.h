#pragma once
#include "BaseComponent.h"
#include "Events.h"
class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const BaseComponent& entity, Event event) = 0;
};

