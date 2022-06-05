#include "LevelComponent.h"
#include "RenderComponent.h"
#include "AnimationComponent.h"
#include "TransformComponent.h"
#include "PlatformComponent.h"
#include "RigidBodyComponent.h"
#include "ColliderComponent.h"
#include <fstream>
#include <iostream>

LevelComponent::LevelComponent(BTEngine::GameObject* pOwner)
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

	assert(m_pPhysicsManager != nullptr);

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
			m_LevelObjects.push_back(ConstructTrapDoor(position));
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

std::shared_ptr<BTEngine::GameObject> LevelComponent::ConstructPlatform(const IVector2& position) {

#pragma region oldPlatform
	//auto platform = std::make_shared<BTEngine::GameObject>();

	////platform->AddComponent<PlatformComponent>();
	//auto transform = platform->AddComponent<TransformComponent>();
	//transform->SetSize(float(m_TileSizeX / 16), float(m_TileSizeY / 16));
	//transform->SetPosition(float(position.x), float(position.y));
	//platform->AddComponent<RenderComponent>();
	//auto animationComp = platform->AddComponent<AnimationComponent>();
	////auto collilsionComp = platform->AddComponent<CollisionComponent>();
	////collilsionComp->SetBoundingBox(Rect{ 0.0f, 0.0f, 16.f, 16.f });
	//auto body = platform->AddComponent<RigidBodyComponent>();
	//body->SetRigidBodyType(RigidType::Static);
	//
	//auto collider = platform->AddComponent<ColliderComponent>();
	//collider->SetBoundingBox(Rect{ 0.0f, 0.0f, 16.0f, 16.0f});
	////collilsionComp->SetOnTriggerCallback([]() {
	////	
	////	std::cout << "Collision on platform" << std::endl;

	////	});
	////m_pPhysicsManager->AddPhysicsBody(collilsionComp);
	//Animation platformAnimation{};
	//platformAnimation.SetSpriteSheet("spritesheet.png");
	//platformAnimation.m_AmountOfColumns = 0;
	//platformAnimation.m_AmountOfRows = 0;
	//platformAnimation.m_CellWidth = 16;
	//platformAnimation.m_CellHeigth = 16;
	//platformAnimation.m_AnimationFramesPerSecond = 0;
	//platformAnimation.m_AnchorPoint = IVector2{ 149, 152 };
	//animationComp->AddAnimation(0, platformAnimation);
	//return platform;
#pragma endregion

#pragma region newPlatform

	auto testObj = std::make_shared<BTEngine::GameObject>();
	auto transformComp = testObj->AddComponent<TransformComponent>();
	transformComp->SetPosition(float(position.x), float(position.y));
	transformComp->SetSize(50.0f, 6.0f);
	testObj->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");
	auto animationComp = testObj->AddComponent<AnimationComponent>();

	Animation platformAnimation{};
	platformAnimation.SetSpriteSheet("spritesheet.png");
	platformAnimation.m_AmountOfColumns = 0;
	platformAnimation.m_AmountOfRows = 0;

	platformAnimation.m_CellWidth = 16;
	platformAnimation.m_CellHeigth = 2;
	platformAnimation.m_AnimationFramesPerSecond = 10;
	platformAnimation.m_AnchorPoint = IVector2{ 150, 167 };

	animationComp->AddAnimation(0, platformAnimation);

	auto testRigid = testObj->AddComponent<RigidBodyComponent>();
	testRigid->SetRigidBodyType(RigidType::Static);
	auto collider = testObj->AddComponent<ColliderComponent>();
	collider->SetBoundingBox(Rect{ 0.0f, 0.0f, 25.0f, 3.0f });

	return testObj;

#pragma endregion

}

std::shared_ptr<BTEngine::GameObject> LevelComponent::ConstructLadder(const IVector2& position) {
	auto ladder = std::make_shared<BTEngine::GameObject>();

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

	auto collilsionComp = ladder->AddComponent<CollisionComponent>();
	collilsionComp->SetBoundingBox(Rect{ 0.0f, 0.0f, 16.f, 16.f });

	m_pPhysicsManager->AddPhysicsBody(collilsionComp);

	ladder->AddComponent<PlatformComponent>();

	return ladder;
}

std::shared_ptr<BTEngine::GameObject> LevelComponent::ConstructTrapDoor(const IVector2& position) {
	auto trapDoor = std::make_shared<BTEngine::GameObject>();

	auto transform = trapDoor->AddComponent<TransformComponent>();
	transform->SetSize(float(m_TileSizeX / 16), float(m_TileSizeY / 16));
	transform->SetPosition(float(position.x), float(position.y));

	trapDoor->AddComponent<RenderComponent>();
	auto animationComp = trapDoor->AddComponent<AnimationComponent>();

	auto collilsionComp = trapDoor->AddComponent<CollisionComponent>();
	collilsionComp->SetBoundingBox(Rect{ 0.0f, 0.0f, 16.f, 16.f });

	m_pPhysicsManager->AddPhysicsBody(collilsionComp);

	Animation trapdoorAnimation{};
	trapdoorAnimation.SetSpriteSheet("spritesheet.png");
	trapdoorAnimation.m_AmountOfColumns = 0;
	trapdoorAnimation.m_AmountOfRows = 0;

	trapdoorAnimation.m_CellWidth = 16;
	trapdoorAnimation.m_CellHeigth = 16;
	trapdoorAnimation.m_AnimationFramesPerSecond = 0;
	trapdoorAnimation.m_AnchorPoint = IVector2{ 166, 153 };

	animationComp->AddAnimation(0, trapdoorAnimation);

	return trapDoor;
}

std::vector<std::shared_ptr<BTEngine::GameObject>>& LevelComponent::GetGameObjects() {
	return m_LevelObjects;
}

void LevelComponent::SetPhysicsManager(std::shared_ptr<PhysicsManager> manager) {
	m_pPhysicsManager = manager;
}