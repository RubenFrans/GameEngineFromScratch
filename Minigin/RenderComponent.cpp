#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TransformComponent.h"
#include "GameObject.h"

RenderComponent::RenderComponent(BTEngine::GameObject* pOwner)
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
	BTEngine::GameObject* parent{GetGameObject()->GetParent()};
	TransformComponent* parentTransformComp{ nullptr };

	if (parent) {
		parentTransformComp = GetGameObject()->GetParent()->GetComponent<TransformComponent>();
	}

	TransformComponent* tc = GetGameObject()->GetComponent<TransformComponent>();

	BTEngine::Transform transform{tc->GetTransform()};

	if (parentTransformComp) {
		BTEngine::Transform pt = parentTransformComp->GetTransform();
		transform.SetPosition(
			pt.GetPosition().x + transform.GetPosition().x,
			pt.GetPosition().y + transform.GetPosition().y,
			pt.GetPosition().z + transform.GetPosition().z);
	}

	if (!tc)
		return;

	BTEngine::Renderer::GetInstance().RenderTexture(*m_pTexture,
		transform.GetPosition().x, transform.GetPosition().y, transform.GetSize().x, transform.GetSize().y,  m_SourceRect, m_FlipHorizontal, m_FlipVertical);
}

void RenderComponent::Initialize()
{
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
