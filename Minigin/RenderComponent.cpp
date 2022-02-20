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
	dae::GameObject* parent{GetGameObject()->GetParent()};
	TransformComponent* parentTransformComp{ nullptr };

	if (parent) {
		parentTransformComp = GetGameObject()->GetParent()->GetComponent<TransformComponent>();
	}

	TransformComponent* tc = GetGameObject()->GetComponent<TransformComponent>();

	dae::Transform transform{tc->GetTransform()};

	if (parentTransformComp) {
		dae::Transform pt = parentTransformComp->GetTransform();
		transform.SetPosition(
			pt.GetPosition().x + transform.GetPosition().x,
			pt.GetPosition().y + transform.GetPosition().y,
			pt.GetPosition().z + transform.GetPosition().z);
	}

	if (!tc)
		return;

	dae::Renderer::GetInstance().RenderTexture(*m_pTexture,
		transform.GetPosition().x, transform.GetPosition().y);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(std::shared_ptr<dae::Texture2D> texture)
{
	m_pTexture = texture;
}
