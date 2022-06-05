#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "RigidBodyComponent.h"
#include "Renderer.h"

ColliderComponent::ColliderComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pFixture{ nullptr }
{
}

void ColliderComponent::Initialize()
{
	// Get the rigidbody component
	m_pRigidBodyComponent = GetGameObject()->GetComponent<RigidBodyComponent>();
	assert(m_pRigidBodyComponent);
}

void ColliderComponent::Update()
{

}

void ColliderComponent::FixedUpdate()
{
	//m_FullLengthBoudingBox.x = m_pRigidBodyComponent->GetPosition().x;
	//m_FullLengthBoudingBox.y = m_pRigidBodyComponent->GetPosition().y;
}

void ColliderComponent::Render() const {

	//BTEngine::Renderer::GetInstance().RenderRect(m_FullLengthBoudingBox);
}