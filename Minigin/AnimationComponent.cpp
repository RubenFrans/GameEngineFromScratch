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
	m_pRenderComponent->FlipHorizontal(m_pCurrentAnimation->m_FlipHorizontal);
	m_pRenderComponent->FlipVertical(m_pCurrentAnimation->m_FlipVertical);
}

void AnimationComponent::FixedUpdate()
{
}

void AnimationComponent::Initialize()
{
	m_pRenderComponent = GetGameObject()->GetComponent<RenderComponent>();

	if (m_Animations.size() > 0) {
		m_pCurrentAnimation = &m_Animations.at(0);
		m_pRenderComponent->SetTexture(m_pCurrentAnimation->m_pSpriteSheet);
	}
}

AnimationComponent* AnimationComponent::AddAnimation(int animationKey, const Animation& animation)
{
	m_Animations.insert(std::pair<int, Animation>(animationKey, animation));
	return this;
}

void AnimationComponent::SetPlayAnimation(int key)
{
	m_pCurrentAnimation = &m_Animations.at(key);
	m_pRenderComponent->SetTexture(m_pCurrentAnimation->m_pSpriteSheet); // this way 1 animation component can use different sprite sheets
}

