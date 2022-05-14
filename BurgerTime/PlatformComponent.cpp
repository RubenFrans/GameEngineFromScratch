#include "PlatformComponent.h"
#include "AnimationComponent.h"

PlatformComponent::PlatformComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
	, m_pAnimationComponent{ nullptr }
{

}

void PlatformComponent::Initialize()
{
	m_pAnimationComponent = GetGameObject()->GetComponent<AnimationComponent>();
	InitializeAnimations();
}

void PlatformComponent::InitializeAnimations() {


	//m_pAnimationComponent->SetPlayAnimation(0);
}

PlatformComponent::~PlatformComponent()
{
}

void PlatformComponent::Update()
{
}

void PlatformComponent::FixedUpdate()
{
}


