#include "MiniginPCH.h"
#include "structs.h"
#include "InternalStructs.h"
#include "ContactListener.h"

#pragma warning(push, 1)
#include "b2_contact.h"
#pragma warning(pop)

#include "ColliderComponent.h"
#include "CircleCollider.h"
void ContactListener::BeginContact(b2Contact* contact)
{
	// std::cout << "Registered contact BEGIN" << std::endl;
	ColliderComponent* collisionCallbackA = reinterpret_cast<ColliderComponent*>(contact->GetFixtureA()->GetUserData().pointer);
	ColliderComponent* collisionCallbackB = reinterpret_cast<ColliderComponent*>(contact->GetFixtureB()->GetUserData().pointer);

	if (collisionCallbackA) {
		collisionCallbackA->TriggerOverlap(collisionCallbackB->GetGameObject(), TriggerAction::Enter);
	}

	if (collisionCallbackB) {
		collisionCallbackB->TriggerOverlap(collisionCallbackA->GetGameObject(), TriggerAction::Enter);
	}

}

void ContactListener::EndContact(b2Contact* contact)
{
	// std::cout << "Registered contact END" << std::endl;

	ColliderComponent* collisionCallbackA = reinterpret_cast<ColliderComponent*>(contact->GetFixtureA()->GetUserData().pointer);
	ColliderComponent* collisionCallbackB = reinterpret_cast<ColliderComponent*>(contact->GetFixtureB()->GetUserData().pointer);

	if (collisionCallbackA) {
		collisionCallbackA->TriggerOverlap(collisionCallbackB->GetGameObject(), TriggerAction::Leave);
	}

	if (collisionCallbackB) {
		collisionCallbackB->TriggerOverlap(collisionCallbackA->GetGameObject(), TriggerAction::Leave);
	}
}

void ContactListener::PreSolve(b2Contact* /*contact*/, const b2Manifold* /*oldManifold*/)
{

}

void ContactListener::PostSolve(b2Contact* /*contact*/, const b2ContactImpulse* /*impulse*/)
{

}
