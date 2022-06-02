#include "MiniginPCH.h"
#include "CollisionComponent.h"

#include "CollisionComponent.h"
#include "TransformComponent.h"

CollisionComponent::CollisionComponent(BTEngine::GameObject* m_pOwner)
	: BaseComponent(m_pOwner)
	, m_BoundingBox{ 0, 0, 16, 16 }
	, m_IsTrigger{ false }
{

}

void CollisionComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
}

void CollisionComponent::Update()
{

}

// Collision detection should be done in the fixedUpdate
void CollisionComponent::FixedUpdate()
{
	m_BoundingBox.x = m_pTransformComponent->GetTransform().GetPosition().x;
	m_BoundingBox.y = m_pTransformComponent->GetTransform().GetPosition().y;
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

const Rect& CollisionComponent::GetBoudingBox() const {
	return m_BoundingBox;
}