#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "World.h"
#include "Scene.h"
#include "b2_body.h"
#include "TransformComponent.h"
#include "b2_fixture.h"
#include "b2_polygon_shape.h"


RigidBodyComponent::RigidBodyComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pRigidBody{ nullptr }, m_InitialPos{}, m_CurrentRigidType{ RigidType::Dynamic }
{

}

void RigidBodyComponent::Initialize() {

	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	m_InitialPos = FVector2{ m_pTransformComponent->GetTransform().GetPosition().x, m_pTransformComponent->GetTransform().GetPosition().y};
	assert(m_pTransformComponent != nullptr);
	InitializeRigidbody();
	m_pTransformComponent->SetPosition(m_pRigidBody->GetPosition().x, m_pRigidBody->GetPosition().y);
}

void RigidBodyComponent::Update() {

	//std::cout << m_pRigidBody->GetPosition().x << " " << m_pRigidBody->GetPosition().y << std::endl;


}

void RigidBodyComponent::FixedUpdate()
{
	m_pTransformComponent->SetPosition(m_pRigidBody->GetPosition().x, m_pRigidBody->GetPosition().y);
	//m_pTransformComponent->Translate(m_pRigidBody->GetLinearVelocity().x, m_pRigidBody->GetLinearVelocity().y);



}

void RigidBodyComponent::SetInitialPosition(const FVector2& initialPos) {

	m_InitialPos = initialPos;
}

RigidBodyComponent::~RigidBodyComponent()
{

}

void RigidBodyComponent::InitializeRigidbody() 
{
	//// Get World to initializeRigidBody
	World* currentSceneWorld = GetGameObject()->GetScene()->GetWorld();
	m_pRigidBody = currentSceneWorld->CreateBody(m_InitialPos);
	m_pRigidBody->SetType(static_cast<b2BodyType>(m_CurrentRigidType));
	m_pRigidBody->SetGravityScale(1.0f);
	m_pRigidBody->SetFixedRotation(true);
}

void RigidBodyComponent::SetRigidBodyType(RigidType type) {
	
	m_CurrentRigidType = type;
	
	if (GetGameObject()->HasBeenInitialized()) {
		m_pRigidBody->SetType(static_cast<b2BodyType>(m_CurrentRigidType));
	}
}

b2Body* RigidBodyComponent::GetBody() const {
	return m_pRigidBody;
}


void RigidBodyComponent::SetVelocity(const FVector2& velocity) {

	m_pRigidBody->SetLinearVelocity({ velocity.x, velocity.y });

}

void RigidBodyComponent::AddForce(const FVector2& force) {

	m_pRigidBody->ApplyLinearImpulseToCenter({ force.x, force.y }, true);

}

b2Fixture* RigidBodyComponent::AddFixtureToBody(const Rect& boundingBox) {

	b2PolygonShape shape;
	shape.SetAsBox(boundingBox.w, boundingBox.h);
	return m_pRigidBody->CreateFixture(&shape, 1.0f);

}