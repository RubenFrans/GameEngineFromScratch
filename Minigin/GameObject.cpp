#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <algorithm>
#include "BaseComponent.h"
#include "RenderComponent.h"


dae::GameObject::~GameObject() {
	for (BaseComponent*& comp : m_Components) {
		delete comp;
		comp = nullptr;
	}
};

void dae::GameObject::Update(){
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
		comp->Update();
		});
}

void dae::GameObject::FixedUpdate(){
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
		comp->FixedUpdate();
		});
}

void dae::GameObject::Render() const
{
	//const auto& pos = m_Transform.GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);

	RenderComponent* rc = GetComponent<RenderComponent>();
	
	if (!rc)
		return;

	rc->Render();
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

