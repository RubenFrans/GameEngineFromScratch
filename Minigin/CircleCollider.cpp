#include "MiniginPCH.h"
#include "CircleCollider.h"
#include "Renderer.h"
#include "b2_fixture.h"

CircleCollider::CircleCollider(BTEngine::GameObject* pOwner)
	: ColliderComponent(pOwner), m_Radius{ 1.0f }
{

}

void CircleCollider::Initialize()
{
	ColliderComponent::Initialize();
	m_pFixture = m_pRigidBodyComponent->AddFixtureToBody(m_Radius, this);
	//if (m_OnCollisionCallback) {
	//}
	//else {

	//	m_pFixture = m_pRigidBodyComponent->AddFixtureToBody(m_Radius);
	//}
}

void CircleCollider::Update()
{

}

void CircleCollider::FixedUpdate()
{
}

void CircleCollider::Render() const
{
	BTEngine::Renderer::GetInstance().RenderCircle(m_pRigidBodyComponent->GetPosition(), m_Radius);
}

void CircleCollider::SetRadius(float radius)
{
	m_Radius = radius;
}
