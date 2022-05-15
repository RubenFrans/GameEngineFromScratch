#pragma once
#include "BaseComponent.h"
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "structs.h"

class RenderComponent;

class LevelComponent final
	: public BaseComponent
{
public:
	LevelComponent(dae::GameObject* pOwner);
	virtual ~LevelComponent();

	void Initialize() override;
	void Update() override;
	void FixedUpdate() override;

	std::vector<std::shared_ptr<dae::GameObject>>& GetGameObjects();

	void SetLevelPath(const std::string& levelPath);

	void ParseLevelFile();
private:

	std::string m_LevelFilePath;
	RenderComponent* m_pRenderComponent;

	std::shared_ptr<dae::GameObject> ConstructPlatform(const IVector2& position);
	std::shared_ptr<dae::GameObject> ConstructLadder(const IVector2& position);
	std::shared_ptr<dae::GameObject> ConstructTrapDoor();

	int m_TileSizeX;
	int m_TileSizeY;

	int m_AmountOfColumns;
	int m_AmountOfRows;

	std::vector<std::shared_ptr<dae::GameObject>> m_LevelObjects;

	// platform locations

	// ladder trigger locations

	// burger ingredient locations

};

