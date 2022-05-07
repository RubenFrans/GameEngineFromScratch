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
	, m_State{ MrPepperState::down }
{
}

void MrPepperComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	m_pAnimationComponent = GetGameObject()->GetComponent<AnimationComponent>();

}


void MrPepperComponent::Update()
{

}

void MrPepperComponent::FixedUpdate()
{

}

void MrPepperComponent::MoveLeft() 
{
	m_pTransformComponent->Translate(-m_HorizontalSpeed * TimeManager::GetDeltaTime(), 0.0f);
	m_pAnimationComponent->SetPlayAnimation((int)MrPepperState::left);
}

void MrPepperComponent::MoveRight()
{
	m_pTransformComponent->Translate(m_HorizontalSpeed * TimeManager::GetDeltaTime(), 0.0f);
	m_pAnimationComponent->SetPlayAnimation((int)MrPepperState::right);
}

void MrPepperComponent::MoveUp()
{
	m_pTransformComponent->Translate(0.0f, -m_VerticalSpeed * TimeManager::GetDeltaTime());
	m_pAnimationComponent->SetPlayAnimation((int)MrPepperState::up);
}

void MrPepperComponent::MoveDown()
{
	m_pTransformComponent->Translate(0.0f, m_VerticalSpeed * TimeManager::GetDeltaTime());
	m_pAnimationComponent->SetPlayAnimation((int)MrPepperState::down);
}

void MrPepperComponent::Die() {
	m_IsDead = true;
	Notify(*this, Event::PLAYER_DIE);
}
