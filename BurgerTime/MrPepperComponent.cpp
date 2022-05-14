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
	InitializeAnimations();
}

void MrPepperComponent::InitializeAnimations() {

	Animation runDownAnimation{};
	runDownAnimation.SetSpriteSheet("spritesheet.png");
	runDownAnimation.m_AmountOfColumns = 2;
	runDownAnimation.m_AmountOfRows = 1;

	runDownAnimation.m_CellWidth = 16;
	runDownAnimation.m_CellHeigth = 16;
	runDownAnimation.m_AnimationFramesPerSecond = 10;

	Animation runRightAnimation{ IVector2{48, 0} };
	runRightAnimation.SetSpriteSheet("spritesheet.png");
	runRightAnimation.m_AmountOfColumns = 2;
	runRightAnimation.m_AmountOfRows = 1;

	runRightAnimation.m_CellWidth = 16;
	runRightAnimation.m_CellHeigth = 16;
	runRightAnimation.m_AnimationFramesPerSecond = 10;
	runRightAnimation.m_FlipHorizontal = true;

	Animation runLeftAnimation{ IVector2{48, 0} };
	runLeftAnimation.SetSpriteSheet("spritesheet.png");
	runLeftAnimation.m_AmountOfColumns = 2;
	runLeftAnimation.m_AmountOfRows = 1;

	runLeftAnimation.m_CellWidth = 16;
	runLeftAnimation.m_CellHeigth = 16;
	runLeftAnimation.m_AnimationFramesPerSecond = 10;

	Animation runUpAnimation{ IVector2{96, 0} };
	runUpAnimation.SetSpriteSheet("spritesheet.png");
	runUpAnimation.m_AmountOfColumns = 2;
	runUpAnimation.m_AmountOfRows = 1;

	runUpAnimation.m_CellWidth = 16;
	runUpAnimation.m_CellHeigth = 16;
	runUpAnimation.m_AnimationFramesPerSecond = 10;


	m_pAnimationComponent->AddAnimation(0, runDownAnimation)
		->AddAnimation(1, runUpAnimation)
		->AddAnimation(2, runLeftAnimation)
		->AddAnimation(3, runRightAnimation);

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
