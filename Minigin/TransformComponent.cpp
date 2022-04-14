#include "MiniginPCH.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(dae::GameObject* pOwner)
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

void TransformComponent::SetTransform(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

void TransformComponent::SetTransform(const dae::Transform& transform)
{
	m_Transform = transform;
}

const dae::Transform& TransformComponent::GetTransform() const
{
	return m_Transform;
}