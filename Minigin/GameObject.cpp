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

void dae::GameObject::SetParent(dae::GameObject* parent)
{
	m_Parent = parent;
}

dae::GameObject* dae::GameObject::GetParent() const
{
	return m_Parent;
}

size_t dae::GameObject::GetAmountOfChildren() const
{
	return m_Children.size();
}

dae::GameObject* dae::GameObject::GetChildAt(int index)
{
	return m_Children.at(index);
}

void dae::GameObject::RemoveChild(int index)
{
	m_Children.at(index)->SetParent(nullptr);
	m_Children.erase(m_Children.begin() + index);
}

void dae::GameObject::AddChild(dae::GameObject* gameObject)
{
	gameObject->SetParent(this);
	m_Children.push_back(gameObject);
}

