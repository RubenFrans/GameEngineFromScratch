#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "RigidBodyComponent.h"

#include "b2_fixture.h"
#include "b2_polygon_shape.h"

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
	b2PolygonShape shape;
	shape.SetAsBox(m_BoundingBox.x, m_BoundingBox.y);
	// store fixture

	m_pFixture = pBody->GetBody()->CreateFixture(&shape, 1.0f);

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
