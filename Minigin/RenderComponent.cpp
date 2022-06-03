#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"

RenderComponent::RenderComponent(BTEngine::GameObject* pOwner)
	: BaseComponent{ pOwner }
	, m_FlipHorizontal{ false }
	, m_FlipVertical{ false }
	, m_SourceRect{}
	, m_pTransformComponent{ nullptr }
{
}

void RenderComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
}

void RenderComponent::Update()
{
}

void RenderComponent::FixedUpdate()
{
}

void RenderComponent::Render() const
{
	BTEngine::Transform transform = m_pTransformComponent->GetWorldTransform();
	BTEngine::Renderer::GetInstance().RenderTexture(*m_pTexture,
			transform.GetPosition().x, transform.GetPosition().y, transform.GetSize().x, transform.GetSize().y,  m_SourceRect, m_FlipHorizontal, m_FlipVertical);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = BTEngine::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(std::shared_ptr<BTEngine::Texture2D> texture)
{
	m_pTexture = texture;
}

void RenderComponent::SetSourceRect(const SDL_Rect& sourceRect)
{
	m_SourceRect = sourceRect;
}

void RenderComponent::FlipHorizontal(bool flip)
{
	m_FlipHorizontal = flip;
}

void RenderComponent::FlipVertical(bool flip)
{
	m_FlipVertical = flip;
}
