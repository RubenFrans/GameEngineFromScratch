#include "MiniginPCH.h"
#include "CollisionComponent.h"

#include "CollisionComponent.h"
#include "TransformComponent.h"
#include "Renderer.h"
#include "GameObject.h"

CollisionComponent::CollisionComponent(BTEngine::GameObject* m_pOwner)
	: BaseComponent(m_pOwner)
	, m_BoundingBox{ 0, 0, 16, 16 }
	, m_IsTrigger{ false }
{

}

void CollisionComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	
	// After initialization alter bounding box to the scale transform. original bounding box should be set to original asset size.
	m_BoundingBox.w = m_BoundingBox.w * m_pTransformComponent->GetWorldTransform().GetSize().x;
	m_BoundingBox.h = m_BoundingBox.h * m_pTransformComponent->GetWorldTransform().GetSize().y;
}

void CollisionComponent::Update()
{
	BTEngine::Renderer::GetInstance().RenderRect(m_BoundingBox);
}

// Collision detection should be done in the fixedUpdate
void CollisionComponent::FixedUpdate()
{
	m_BoundingBox.x = m_pTransformComponent->GetWorldTransform().GetPosition().x;
	m_BoundingBox.y = m_pTransformComponent->GetWorldTransform().GetPosition().y;
}

void CollisionComponent::SetBoundingBox(const Rect& boundingBox)
{
	m_OriginalBoundingBox = boundingBox;
	m_BoundingBox = boundingBox;
}

void CollisionComponent::SetTrigger(bool isTrigger)
{
	m_IsTrigger = isTrigger;
}

void CollisionComponent::SetOnTriggerCallback(const std::function<void(BTEngine::GameObject* pTriggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action)>& callBack) {

	m_OnTriggerCallback = callBack;
}

void CollisionComponent::TriggerOverlap(BTEngine::GameObject* pTriggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action) {
	
	assert(pTriggerObject != nullptr);
	assert(pOtherObject != nullptr);
	
	if (m_OnTriggerCallback) {
		m_OnTriggerCallback(pTriggerObject, pOtherObject, action);
	}
}

const Rect& CollisionComponent::GetBoudingBox() const {
	return m_BoundingBox;
}