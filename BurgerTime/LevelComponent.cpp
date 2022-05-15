#include "LevelComponent.h"
#include "RenderComponent.h"
#include "AnimationComponent.h"
#include "TransformComponent.h"
#include "PlatformComponent.h"
#include <fstream>

LevelComponent::LevelComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
	, m_LevelFilePath{ }
	, m_AmountOfColumns{ 13 }
	, m_AmountOfRows{ 12 }
	, m_TileSizeX{ 800 / 16 }
	, m_TileSizeY{ 600 / 16 }
{
	//ParseLevelFile();
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

void LevelComponent::SetLevelPath(const std::string& levelPath) {
	m_LevelFilePath = levelPath;
}

void LevelComponent::ParseLevelFile()
{
	std::ifstream input{ m_LevelFilePath };

	char objectIdentfier{};
	int currentColumn{ 0 };
	int currentRow{ 0 };
	while (input.good())
	{
		input.read(&objectIdentfier, sizeof(char));
		IVector2 position{ currentColumn * m_TileSizeX, currentRow * m_TileSizeY };
		currentColumn++;
		switch (objectIdentfier)
		{
		case '_':
			m_LevelObjects.push_back(ConstructPlatform(position));
			break;
		case '-':
			ConstructTrapDoor();
			break;
		case '=':
			m_LevelObjects.push_back(ConstructLadder(position));
			break;
		case '\n':
			currentRow++;
			currentColumn = 0;
		default:
			//ConstructPlatform(position);
			break;
		}
		

	}
}

std::shared_ptr<dae::GameObject> LevelComponent::ConstructPlatform(const IVector2& position) {

	auto platform = std::make_shared<dae::GameObject>();

	platform->AddComponent<PlatformComponent>();
	auto transform = platform->AddComponent<TransformComponent>();
	transform->SetSize(float(m_TileSizeX / 16), float(m_TileSizeY / 16));
	transform->SetPosition(float(position.x), float(position.y));

	platform->AddComponent<RenderComponent>();
	auto animationComp = platform->AddComponent<AnimationComponent>();

	Animation platformAnimation{};
	platformAnimation.SetSpriteSheet("spritesheet.png");
	platformAnimation.m_AmountOfColumns = 0;
	platformAnimation.m_AmountOfRows = 0;

	platformAnimation.m_CellWidth = 16;
	platformAnimation.m_CellHeigth = 16;
	platformAnimation.m_AnimationFramesPerSecond = 0;
	platformAnimation.m_AnchorPoint = IVector2{ 149, 152 };

	animationComp->AddAnimation(0, platformAnimation);

	return platform;

}

std::shared_ptr<dae::GameObject> LevelComponent::ConstructLadder(const IVector2& position) {
	auto ladder = std::make_shared<dae::GameObject>();

	//ladder->AddComponent<LadderComponent>();
	auto transform = ladder->AddComponent<TransformComponent>();
	transform->SetSize(float(m_TileSizeX / 16), float(m_TileSizeY / 16));
	transform->SetPosition(float(position.x), float(position.y));

	ladder->AddComponent<RenderComponent>();
	auto animationComp = ladder->AddComponent<AnimationComponent>();

	Animation ladderAnimation{};
	ladderAnimation.SetSpriteSheet("spritesheet.png");
	ladderAnimation.m_AmountOfColumns = 0;
	ladderAnimation.m_AmountOfRows = 0;

	ladderAnimation.m_CellWidth = 16;
	ladderAnimation.m_CellHeigth = 16;
	ladderAnimation.m_AnimationFramesPerSecond = 0;
	ladderAnimation.m_AnchorPoint = IVector2{ 182, 152 };

	animationComp->AddAnimation(0, ladderAnimation);

	return ladder;
}

std::shared_ptr<dae::GameObject> LevelComponent::ConstructTrapDoor() {
	auto obj = std::make_shared<dae::GameObject>();
	return obj;
}

std::vector<std::shared_ptr<dae::GameObject>>& LevelComponent::GetGameObjects() {
	return m_LevelObjects;
}