#pragma once
#include "BaseComponent.h"
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "structs.h"
#include "PhysicsManager.h"

class RenderComponent;

class LevelComponent final
	: public BaseComponent
{
public:
	LevelComponent(BTEngine::GameObject* pOwner);
	virtual ~LevelComponent();

	void Initialize() override;
	void Update() override;
	void FixedUpdate() override;

	std::vector<std::shared_ptr<BTEngine::GameObject>>& GetGameObjects();

	void SetLevelPath(const std::string& levelPath);

	void ParseLevelFile();

	void SetPhysicsManager(std::shared_ptr<PhysicsManager> phyicsManager);

private:

	std::string m_LevelFilePath;
	RenderComponent* m_pRenderComponent;

	std::shared_ptr<BTEngine::GameObject> ConstructPlatform(const IVector2& position);
	std::shared_ptr<BTEngine::GameObject> ConstructLadder(const IVector2& position);
	std::shared_ptr<BTEngine::GameObject> ConstructTrapDoor(const IVector2& position);

	int m_TileSizeX;
	int m_TileSizeY;

	int m_AmountOfColumns;
	int m_AmountOfRows;

	std::vector<std::shared_ptr<BTEngine::GameObject>> m_LevelObjects;

	std::shared_ptr<PhysicsManager> m_pPhysicsManager;

	// platform locations

	// ladder trigger locations

	// burger ingredient locations

};

