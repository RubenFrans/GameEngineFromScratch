#pragma once
#include "BaseComponent.h"
#include <string>

class RenderComponent;

class LevelComponent final
	: BaseComponent
{
public:
	LevelComponent(dae::GameObject* pOwner, const std::string& levelFilePath);
	virtual ~LevelComponent();

	void Initialize() override;
	void Update() override;
	void FixedUpdate() override;

private:
	void ParseLevelFile();

	std::string m_LevelFilePath;
	RenderComponent* m_pRenderComponent;

	// platform locations

	// ladder trigger locations

	// burger ingredient locations

};

