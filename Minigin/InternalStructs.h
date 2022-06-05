#pragma once
#include <functional>

#include "structs.h"
#include "GameObject.h"
//#include "b2_settings.h"

struct CollisionInfo /*: b2FixtureUserData*/ {
	BTEngine::GameObject* colliderOwner;
	std::function<void(BTEngine::GameObject* collidedObject, TriggerAction action)> collisionCallback;
};
