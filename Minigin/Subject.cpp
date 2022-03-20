#include "MiniginPCH.h"
#include "Subject.h"

void Subject::AddObserver(Observer* observer)
{
	observers.insert(observer);
}

void Subject::RemoveObserver(Observer* observer)
{
	observers.erase(observer);
}

void Subject::Notify(const BaseComponent& component, Event event)
{
	for (auto observer : observers) {
		observer->onNotify(component, event);
	}
}
