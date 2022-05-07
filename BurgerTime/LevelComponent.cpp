#include "LevelComponent.h"
#include "RenderComponent.h"

LevelComponent::LevelComponent(dae::GameObject* pOwner, const std::string& levelFilePath)
	: BaseComponent{ pOwner }, m_LevelFilePath{ levelFilePath }
{

}

LevelComponent::~LevelComponent()
{

}

void LevelComponent::Initialize()
{
	m_pRenderComponent = GetGameObject()->GetComponent<RenderComponent>();
}

void LevelComponent::Update()
{

}

void LevelComponent::FixedUpdate()
{
}

void LevelComponent::ParseLevelFile() 
{

}
