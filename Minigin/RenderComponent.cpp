#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"

RenderComponent::RenderComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void RenderComponent::Update()
{
}

void RenderComponent::FixedUpdate()
{
}

void RenderComponent::Render() const
{
	//const auto& pos = m_Transform.GetPosition();
	const float x{50.0f};
	const float y{50.0f};
	dae::Renderer::GetInstance().RenderTexture(*m_pTexture, x, y);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(std::shared_ptr<dae::Texture2D> texture)
{
	m_pTexture = texture;
}
