#include "MiniginPCH.h"
#include "BoxCollider.h"
#include "Renderer.h"
#include "b2_fixture.h"

BoxCollider::BoxCollider(BTEngine::GameObject* pOwner)
	: ColliderComponent(pOwner), m_BoundingBox{}
{
}

void BoxCollider::Initialize()
{
	ColliderComponent::Initialize();
	m_pFixture = m_pRigidBodyComponent->AddFixtureToBody(m_BoundingBox, this);
}

void BoxCollider::Update()
{
	
}

void BoxCollider::FixedUpdate()
{
	m_FullLengthBoudingBox.x = m_pRigidBodyComponent->GetPosition().x;
	m_FullLengthBoudingBox.y = m_pRigidBodyComponent->GetPosition().y;
}

void BoxCollider::Render() const {

	BTEngine::Renderer::GetInstance().RenderRect(m_FullLengthBoudingBox);
}

// Bounding box interpreted as half width and halfheight
void BoxCollider::SetBoundingBox(const Rect& boundingBox)
{
	m_BoundingBox = boundingBox;
	m_FullLengthBoudingBox = boundingBox;
	m_FullLengthBoudingBox.w = m_FullLengthBoudingBox.w * 2.0f;
	m_FullLengthBoudingBox.h = m_FullLengthBoudingBox.h * 2.0f;
}