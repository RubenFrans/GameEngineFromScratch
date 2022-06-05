#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <algorithm>
#include "BaseComponent.h"
#include "RenderComponent.h"

BTEngine::GameObject::GameObject() 
	: SceneObject{}, m_pParent{ nullptr }, m_Components{}, m_Children{}, m_Tag{}, m_HasBeenInitialized{ false }
{
}

BTEngine::GameObject::~GameObject() {
	for (BaseComponent*& comp : m_Components) {
		delete comp;
		comp = nullptr;
	}
};

void BTEngine::GameObject::Update(){
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
		comp->Update();
		});

	//std::for_each(m_Children.begin(), m_Children.end(), [](BTEngine::GameObject* child) {
	//		child->Update();
	//	});
}

void BTEngine::GameObject::FixedUpdate(){
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
		comp->FixedUpdate();
		});

	//std::for_each(m_Children.begin(), m_Children.end(), [](BTEngine::GameObject* child) {
	//	child->FixedUpdate();
	//	});
}

void BTEngine::GameObject::Render() const
{
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
			comp->Render();
		});

	//std::for_each(m_Children.begin(), m_Children.end(), [](BTEngine::GameObject* child) {
	//	child->Render();
	//	});
}

void BTEngine::GameObject::Initialize()
{
	std::for_each(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
		comp->Initialize();
		});

	//std::for_each(m_Children.begin(), m_Children.end(), [](BTEngine::GameObject* child) {
	//	child->Initialize();
	//	});

	m_HasBeenInitialized = true;
}

void BTEngine::GameObject::SetParent(BTEngine::GameObject* parent)
{
	m_pParent = parent;
}

BTEngine::GameObject* BTEngine::GameObject::GetParent() const
{
	return m_pParent;
}

size_t BTEngine::GameObject::GetAmountOfChildren() const
{
	return m_Children.size();
}

BTEngine::GameObject* BTEngine::GameObject::GetChildAt(int index)
{
	return m_Children.at(index);
}

void BTEngine::GameObject::RemoveChild(int index)
{
	m_Children.at(index)->SetParent(nullptr);
	m_Children.at(index)->OnDetached();
	m_Children.erase(m_Children.begin() + index);
}

void BTEngine::GameObject::AddChild(BTEngine::GameObject* gameObject)
{
	gameObject->SetParent(this);
	gameObject->OnAttached();
	m_Children.push_back(gameObject);
}

void BTEngine::GameObject::OnAttached() {

}

void BTEngine::GameObject::OnDetached() {

}

void BTEngine::GameObject::SetTag(const std::string& tag) {
	m_Tag = tag;
}

const std::string& BTEngine::GameObject::GetTag() const {
	return m_Tag;
}

bool BTEngine::GameObject::HasBeenInitialized() const {
	return m_HasBeenInitialized;
}

