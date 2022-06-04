#include "IngredientPartComponent.h"
#include "CollisionComponent.h"
#include "MrPepperComponent.h"
#include <string>
#include "TransformComponent.h"

IngredientPartComponent::IngredientPartComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner)
	, m_SteppedOver{ false }
	, m_SteppedOnPosOffset{ 0.0f, 10.0f }
	, m_TriggerCallback{}
	, m_pTransformComponent{ nullptr }
{

}

void IngredientPartComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	InitializeCollisions();
}

void IngredientPartComponent::InitializeCollisions() {

	CollisionComponent* collisionComponent = GetGameObject()->GetComponent<CollisionComponent>();

	assert(collisionComponent != nullptr);

	collisionComponent->SetOnTriggerCallback([&](BTEngine::GameObject* pTriggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action) {
		
			OnTriggerCallback(pTriggerObject, pOtherObject, action);

		});
	
}

void IngredientPartComponent::OnTriggerCallback(BTEngine::GameObject* /*pTriggerObject*/, BTEngine::GameObject* pOtherObject, TriggerAction action) {

	// Only execute when not yet stepped over
	if (m_SteppedOver)
		return;

	if (pOtherObject && pOtherObject->GetTag().compare("Peter") == 0) {

		if (action == TriggerAction::Enter) {
			
			m_pTransformComponent->Translate(m_SteppedOnPosOffset.x, m_SteppedOnPosOffset.y);

			m_SteppedOver = true;
			
		}
	}
}

void IngredientPartComponent::Update()
{

}

void IngredientPartComponent::FixedUpdate()
{

}
