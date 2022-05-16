#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void BTEngine::SceneManager::Update()
{
	for(auto& scene : m_Scenes)
	{
		scene->Update();
	}
}

void BTEngine::SceneManager::FixedUpdate() {
	for (auto& scene : m_Scenes) {
		
		scene->FixedUpdate();
	}
}

void BTEngine::SceneManager::Render()
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}
}

void BTEngine::SceneManager::Initialize()
{
	for (const auto& scene : m_Scenes)
	{
		scene->Initialize();
	}
}

BTEngine::Scene& BTEngine::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}
