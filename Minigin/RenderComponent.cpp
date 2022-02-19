#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TransformComponent.h"
#include "GameObject.h"

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

	TransformComponent* tc = GetGameObject()->GetComponent<TransformComponent>();

	if (!tc)
		return;

	dae::Renderer::GetInstance().RenderTexture(*m_pTexture,
		tc->GetTransform().GetPosition().x, tc->GetTransform().GetPosition().y);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(std::shared_ptr<dae::Texture2D> texture)
{
	m_pTexture = texture;
}
