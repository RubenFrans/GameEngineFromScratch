#include "MiniginPCH.h"
#include "AnimationComponent.h"
#include "ResourceManager.h"
#include "RenderComponent.h"

AnimationComponent::AnimationComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner },
	m_pSpriteSheet{},
	m_Animations{},
	m_pCurrentAnimation{ nullptr }
{
}

void AnimationComponent::Update()
{
	m_pCurrentAnimation->UpdateCurrentFrame();
	m_pRenderComponent->SetSourceRect(m_pCurrentAnimation->GetCurrentFrameTexture());
}

void AnimationComponent::FixedUpdate()
{
}

void AnimationComponent::Initialize()
{
	m_pRenderComponent = GetGameObject()->GetComponent<RenderComponent>();

	m_pCurrentAnimation = &m_Animations.at(0);

	m_pRenderComponent->SetTexture(m_pCurrentAnimation->m_pSpriteSheet);
}

void AnimationComponent::AddAnimation(int animationKey, const Animation& animation)
{
	m_Animations.insert(std::pair<int, Animation>(animationKey, animation));
}

void AnimationComponent::SetPlayAnimation(int)
{

}

