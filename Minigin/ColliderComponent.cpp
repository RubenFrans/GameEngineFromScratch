#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "RigidBodyComponent.h"

ColliderComponent::ColliderComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pFixture{ nullptr }, m_BoundingBox{}
{
}

void ColliderComponent::Initialize()
{
	// Get the rigidbody component
	RigidBodyComponent* pBody = GetGameObject()->GetComponent<RigidBodyComponent>();

	assert(pBody);

	// Create fixture

	// store fixture

	m_pFixture = pBody->AddFixtureToBody(m_BoundingBox);

}

void ColliderComponent::Update()
{

}

void ColliderComponent::FixedUpdate()
{

}

// Bounding box interpreted as half width and halfheight
void ColliderComponent::SetBoundingBox(const Rect& boundingBox)
{
	m_BoundingBox = boundingBox;
}
