#include "MiniginPCH.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(BTEngine::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_Transform{}
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

}

void TransformComponent::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

void TransformComponent::SetSize(float x, float y) {
	m_Transform.SetSize(x, y, 0.0f);
}

void TransformComponent::SetTransform(const BTEngine::Transform& transform)
{
	m_Transform = transform;
}

void TransformComponent::Translate(float x, float y) {

	glm::vec3 pos = m_Transform.GetPosition();

	m_Transform.SetPosition(pos.x + x, pos.y + y, pos.z);

}

const BTEngine::Transform& TransformComponent::GetTransform() const
{
	return m_Transform;
}