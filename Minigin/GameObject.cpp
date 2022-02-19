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
	RenderComponent* rc = GetComponent<RenderComponent>();

	if (!rc)
		return;

	rc->Render();
}

