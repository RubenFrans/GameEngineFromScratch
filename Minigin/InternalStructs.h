#pragma once
#include <functional>
#include "structs.h"
#include "GameObject.h"

struct CollisionInfo {
	BTEngine::GameObject* colliderOwner;
	std::function<void(BTEngine::GameObject* collidedObject, TriggerAction action)> collisionCallback;
};
