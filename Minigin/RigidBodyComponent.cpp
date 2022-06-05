#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "World.h"
#include "Scene.h"
#include "b2_body.h"
#include "TransformComponent.h"
#include "b2_fixture.h"
#include "b2_polygon_shape.h"
#include "b2_circle_shape.h"
#include "b2_settings.h"
#include "InternalStructs.h"
#include "ColliderComponent.h"


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

}

void RigidBodyComponent::FixedUpdate()
{
	m_pTransformComponent->SetPosition(m_pRigidBody->GetPosition().x, m_pRigidBody->GetPosition().y);
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

b2Fixture* RigidBodyComponent::AddFixtureToBody(const Rect& boundingBox, ColliderComponent* pColliderComponent) {

	b2PolygonShape shape;
	shape.SetAsBox(boundingBox.w, boundingBox.h);
	b2FixtureDef def{};
	def.shape = &shape; // shape is cloned so it is ok to make it on the stack
	def.density = 1.0f;
	def.isSensor = pColliderComponent->IsSensor();
	def.userData.pointer = reinterpret_cast<uintptr_t>(pColliderComponent);

	return m_pRigidBody->CreateFixture(&def);

}

b2Fixture* RigidBodyComponent::AddFixtureToBody(float radius, ColliderComponent* pColliderComponent) {

	b2CircleShape shape;
	shape.m_radius = radius;
	b2FixtureDef def{};
	def.shape = &shape; // shape is cloned so it is ok to make it on the stack
	def.density = 1.0f;
	def.isSensor = pColliderComponent->IsSensor();
	def.userData.pointer = reinterpret_cast<uintptr_t>(pColliderComponent);
	
	b2Fixture* pFixture = m_pRigidBody->CreateFixture(&def);

	return pFixture;

}

void RigidBodyComponent::SetPosition(const FVector2& position) {

	m_pTransformComponent->SetPosition(position.x, position.y);
	m_pRigidBody->SetTransform({ position.x, position.y }, 0.0f);

}

FVector2 RigidBodyComponent::GetPosition() const {
	FVector2 position{ m_pRigidBody->GetPosition().x, m_pRigidBody->GetPosition().y };
	return position;
}