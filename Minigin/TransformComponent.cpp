#include "MiniginPCH.h"
#include "TransformComponent.h"
//#include "GameObject.h"

TransformComponent::TransformComponent(BTEngine::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_LocalTransform{}
{

}

void TransformComponent::Update()
{

}

void TransformComponent::FixedUpdate()
{
	
}

void TransformComponent::Initialize()
{
	UpdateWorldTransform();
}

void TransformComponent::SetPosition(float x, float y)
{
	m_LocalTransform.SetPosition(x, y, 0.0f);
}

void TransformComponent::SetSize(float x, float y) {
	m_LocalTransform.SetSize(x, y, 0.0f);
}

void TransformComponent::SetTransform(const BTEngine::Transform& transform)
{
	m_LocalTransform = transform;
}

void TransformComponent::Translate(float x, float y) {

	glm::vec3 pos = m_LocalTransform.GetPosition();

	m_LocalTransform.SetPosition(pos.x + x, pos.y + y, pos.z);

	// Update world transform
	UpdateWorldTransform();

}

const BTEngine::Transform& TransformComponent::GetTransform() const
{
	return m_LocalTransform;
}

const BTEngine::Transform& TransformComponent::GetWorldTransform() const {

	return m_WorldTransform;

}

void TransformComponent::UpdateWorldTransform() {
	BTEngine::GameObject* pOwner = GetGameObject();
	BTEngine::GameObject* pObjectParent = pOwner->GetParent();

	// If the object has no parent its local transform is also its worldtransform
	if (pObjectParent == nullptr) {
		m_WorldTransform = m_LocalTransform;
		return;
	}

	BTEngine::Transform parentTransform{ pObjectParent->GetComponent<TransformComponent>()->GetTransform() }; // Getting this should be moved to an onAttachToParent / Child event

	m_WorldTransform = m_LocalTransform + parentTransform;
}