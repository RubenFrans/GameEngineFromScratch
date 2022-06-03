#pragma once
#include "SceneManager.h"
#include "PhysicsManager.h"

namespace BTEngine
{
	class SceneObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<SceneObject>& object);

		void Update();
		void FixedUpdate();
		void Render() const;
		void Initialize(); // Calls initilize function on all gameobjects

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector < std::shared_ptr<SceneObject>> m_Objects{};
		bool m_HasBeenInitialized;
		static unsigned int m_IdCounter; 

		//PhysicsManager m_PhysicsManager;

	};

}
