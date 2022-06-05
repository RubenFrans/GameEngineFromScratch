#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "World.h"
#include "Scene.h"
#include "b2_body.h"
#include "TransformComponent.h"


RigidBodyComponent::RigidBodyComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pRigidBody{ nullptr }, m_InitialPos{}
{

}

void RigidBodyComponent::Initialize() {

	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	assert(m_pTransformComponent != nullptr);
	InitializeRigidbody();
}

void RigidBodyComponent::Update() {

	m_pTransformComponent->Translate(m_pRigidBody->GetLinearVelocity().x, m_pRigidBody->GetLinearVelocity().y);
	std::cout << m_pRigidBody->GetPosition().x << " " << m_pRigidBody->GetPosition().y << std::endl;
}

void RigidBodyComponent::FixedUpdate()
{

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
	m_pRigidBody->SetGravityScale(1.0f);
}

b2Body* RigidBodyComponent::GetBody() const {
	return m_pRigidBody;
}
