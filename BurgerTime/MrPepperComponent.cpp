#pragma once
#include "MiniginPCH.h"
#include "MrPepperComponent.h"
#include "TransformComponent.h"
#include "TimeManager.h"
#include "AnimationComponent.h"

MrPepperComponent::MrPepperComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_IsDead{ false }
	, m_HorizontalSpeed{ 50.0f }
	, m_VerticalSpeed{ 50.0f }
{

}

void MrPepperComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	m_pAnimationComponent = GetGameObject()->GetComponent<AnimationComponent>();

	InitializeAnimations();

}

void MrPepperComponent::InitializeAnimations() {



}

void MrPepperComponent::Update()
{

}

void MrPepperComponent::FixedUpdate()
{

}

void MrPepperComponent::MoveLeft() 
{
	m_pTransformComponent->Translate(m_HorizontalSpeed * TimeManager::GetDeltaTime(), 0.0f);
}

void MrPepperComponent::MoveRight()
{
	m_pTransformComponent->Translate(-m_HorizontalSpeed * TimeManager::GetDeltaTime(), 0.0f);
}

void MrPepperComponent::MoveUp()
{
	m_pTransformComponent->Translate(0.0f, -m_VerticalSpeed * TimeManager::GetDeltaTime());
}

void MrPepperComponent::MoveDown()
{
	m_pTransformComponent->Translate(0.0f, m_VerticalSpeed * TimeManager::GetDeltaTime());
}

void MrPepperComponent::Die() {
	m_IsDead = true;
	Notify(*this, Event::PLAYER_DIE);
}
