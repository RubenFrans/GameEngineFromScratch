#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <vector>

class BaseComponent;

namespace dae
{
	class Texture2D;

	// should be marked as final GameObjects will be constructed by adding different GameObjects
	class GameObject : public SceneObject
	{
	public:

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject & other) = delete;
		GameObject(GameObject && other) = delete;
		GameObject& operator=(const GameObject & other) = delete;
		GameObject& operator=(GameObject && other) = delete;

		void Update() override;
		void FixedUpdate() override;
		void Render() const override;

		template <typename T> T* AddComponent();
		template <typename T> T* GetComponent() const;
		template <typename T> void RemoveComponent();

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);



	private:
		Transform m_Transform; // should be transform component
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_pTexture{}; // shoud be in a render component

		std::vector<BaseComponent*> m_Components;

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

		// maybe replace by algorithm
		T* result{nullptr};
		for (BaseComponent* comp : m_Components) {
			if (typeid(*comp) == typeid(T)) {
				result = dynamic_cast<T*>(comp);
			}
		}

		return result;
	}
	template<typename T>
	inline void GameObject::RemoveComponent()
	{
	}
}
