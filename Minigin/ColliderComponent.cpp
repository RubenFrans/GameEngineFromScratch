#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "RigidBodyComponent.h"
#include "Renderer.h"
#include "InternalStructs.h"

ColliderComponent::ColliderComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner)
	, m_pFixture{ nullptr }
	, m_pRigidBodyComponent{ nullptr }
	, m_IsSensor{ false }
	, m_ShowPhysicsDebug{ false }
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

}

void ColliderComponent::Render() const {

}

void ColliderComponent::SetCollisionCallback(const std::function<void(BTEngine::GameObject* pCollidedObject, TriggerAction action)>& callBack) {

	m_OnCollisionCallback = callBack;
}

void ColliderComponent::TriggerOverlap(BTEngine::GameObject* pOtherGameObject, TriggerAction action) {

	if (m_OnCollisionCallback) {
		m_OnCollisionCallback(pOtherGameObject, action);
	}
}

void ColliderComponent::SetIsSensor(bool isSensor) {
	m_IsSensor = isSensor;
}

bool ColliderComponent::IsSensor() const {
	return m_IsSensor;
}