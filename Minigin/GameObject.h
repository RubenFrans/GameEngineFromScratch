#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <vector>

class BaseComponent;

namespace dae
{
	class Texture2D;

	class GameObject final : public SceneObject
	{
	public:
		GameObject();
		~GameObject(); // no virtual because class is final
		GameObject(const GameObject & other) = delete;
		GameObject(GameObject && other) = delete;
		GameObject& operator=(const GameObject & other) = delete;
		GameObject& operator=(GameObject && other) = delete;

		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Initialize() override;

		template <typename T> T* AddComponent();
		template <typename T> T* GetComponent() const;
		template <typename T> void RemoveComponent();

		void SetParent(GameObject* parent);
		GameObject* GetParent() const;

		size_t GetAmountOfChildren() const;
		GameObject* GetChildAt(int index);
		void RemoveChild(int index);
		void AddChild(GameObject* gameObject);

	private:
		GameObject* m_pParent;
		std::vector<BaseComponent*> m_Components;
		std::vector<GameObject*> m_Children; // Think to change to set for unique entries (no gameobject should be added twice as child to the same go)
	};

	template<typename T>
	inline T* GameObject::AddComponent()
	{
		T* component = new T{this};
		m_Components.push_back(component);

		return component;
	}
	template<typename T>
	inline T* GameObject::GetComponent() const
	{
		T* result{nullptr};
		for (BaseComponent* comp : m_Components) {
			if (typeid(*comp) == typeid(T)) { // you can also just use dynamic cast in for loop and not check type id's
				result = dynamic_cast<T*>(comp);
				break;
			}
		}

		return result;
	}
	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		auto it = std::remove_if(m_Components.begin(), m_Components.end(), [](BaseComponent* comp) {
			if (typeid(*comp) == typeid(T)) {
				return true;
			}
			return false;
			});

		delete *it;
		m_Components.erase(it, m_Components.end());
	}
}
