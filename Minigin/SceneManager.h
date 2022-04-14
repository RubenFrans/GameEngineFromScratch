#pragma once
#include "Singleton.h"
#include <string>
#include <vector>
#include <memory>
namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Update();
		void FixedUpdate();
		void Render();
		void Initialize(); // Calls initialize on all gameobjects and its components
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
	};
}
