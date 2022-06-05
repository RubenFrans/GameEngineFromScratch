#include "MiniginPCH.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "World.h"
#include "Scene.h"
#include "b2_body.h"


RigidBodyComponent::RigidBodyComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner), m_pRigidBody{ nullptr }, m_InitialPos{}
{

}

void RigidBodyComponent::Initialize() {

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
	//World* currentSceneWorld = GetGameObject()->GetScene()->GetWorld();
	//currentSceneWorld->CreateBody(m_InitialPos);
}
