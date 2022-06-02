#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(BTEngine::GameObject* m_pOwner)
	: BaseComponent(m_pOwner)
	, m_BoundingBox{ 0, 0, 16, 16 }
	, m_IsTrigger{ false }
{

}

void CollisionComponent::Initialize()
{
	
}

void CollisionComponent::Update()
{

}

// Collision detection should be done in the fixedUpdate
void CollisionComponent::FixedUpdate()
{

}

void CollisionComponent::SetBoundingBox(const Rect& boundingBox)
{
	m_BoundingBox = boundingBox;
}

void CollisionComponent::SetTrigger(bool isTrigger)
{
	m_IsTrigger = isTrigger;
}

void CollisionComponent::SetOnTriggerCallback(const std::function<void()>& callBack) {

	m_OnTriggerCallback = callBack;
}

void CollisionComponent::TriggerOverlap() {
	m_OnTriggerCallback();
}
