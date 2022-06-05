#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "RigidBodyComponent.h"
#include "Renderer.h"

ColliderComponent::ColliderComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pFixture{ nullptr }, m_BoundingBox{}
{
}

void ColliderComponent::Initialize()
{
	// Get the rigidbody component
	m_pRigidBodyComponent = GetGameObject()->GetComponent<RigidBodyComponent>();

	assert(m_pRigidBodyComponent);

	// Create fixture

	// store fixture

	m_pFixture = m_pRigidBodyComponent->AddFixtureToBody(m_BoundingBox);

}

void ColliderComponent::Update()
{

}

void ColliderComponent::FixedUpdate()
{
	m_FullLengthBoudingBox.x = m_pRigidBodyComponent->GetPosition().x;
	m_FullLengthBoudingBox.y = m_pRigidBodyComponent->GetPosition().y;
}

void ColliderComponent::Render() const {

	BTEngine::Renderer::GetInstance().RenderRect(m_FullLengthBoudingBox);
}

// Bounding box interpreted as half width and halfheight
void ColliderComponent::SetBoundingBox(const Rect& boundingBox)
{
	m_BoundingBox = boundingBox;
	m_FullLengthBoudingBox = boundingBox;
	m_FullLengthBoudingBox.w = m_FullLengthBoudingBox.w * 2.0f;
	m_FullLengthBoudingBox.h = m_FullLengthBoudingBox.h * 2.0f;

}
