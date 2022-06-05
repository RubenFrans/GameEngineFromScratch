#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "World.h"

using namespace BTEngine;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) 
	: m_Name(name), m_HasBeenInitialized{ false } 
{
	m_pWorld = new World();
}

Scene::~Scene() 
{
	delete m_pWorld;
}

void Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	m_Objects.push_back(object);
	object->SetScene(this);

	// If the scene already is initialized (thus the object is being added at runtime during the game after initialization) initialize the object manually here.
	if (m_HasBeenInitialized) {
		object->Initialize();
	}

}

void Scene::Update()
{
	m_pWorld->Update();

	for(auto& object : m_Objects)
	{
		object->Update();
	}
}

void Scene::FixedUpdate() {
	
	m_pWorld->FixedUpdate();

	for (auto& object : m_Objects) {
		object->FixedUpdate();
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();
	}
}

void BTEngine::Scene::Initialize()
{
	for (auto& object : m_Objects)
	{
		object->Initialize();
	}

	m_HasBeenInitialized = true;
}

World* Scene::GetWorld() const {
	return m_pWorld;
}

