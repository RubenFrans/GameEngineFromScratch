#pragma once
#include "BurgerEngine.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "Scene.h"
#include "TextComponent.h"
#include "LivesComponent.h"
#include "MrPepperComponent.h"
#include "InputManager2.h"
#include "AchievementSystem.h"
#include "PointsComponent.h"
#include "Commands.h"
#include "AnimationComponent.h"
#include "AudioSystemLocator.h"
#include "PlatformComponent.h"
#include "LevelComponent.h"
#include "PhysicsManager.h"
#include <iostream>
#include "IngridientComponent.h"
#include "RigidBodyComponent.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

using namespace BTEngine;

void BurgerEngine::Initialize()
{
	BTEngine::Minigin::Initialize();
}

/*
* Loading and scene construction starts here
*/
void BurgerEngine::LoadGame()
{
	BTEngine::Minigin::LoadGame();
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	AudioSystemLocator::GetAudio().LoadAudioClip(0, "Navi - Hey.mp3", true);

	auto physics = std::make_shared<PhysicsManager>();
	scene.Add(physics);

#pragma region MrPepper
	auto mrPepper = std::make_shared<GameObject>();
	mrPepper->SetTag("Peter");
	auto pepperComp = mrPepper->AddComponent<MrPepperComponent>();

	auto pepperTransform = mrPepper->AddComponent<TransformComponent>();
	pepperTransform->SetSize(50.0f, 50.0f);
	pepperTransform->Translate(0.0f, 100.0f);
	mrPepper->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");
	mrPepper->AddComponent<AnimationComponent>();


	mrPepper->AddComponent<RigidBodyComponent>();
	auto collider = mrPepper->AddComponent<CircleCollider>();
		collider->SetRadius(25.0f);
	
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Right, std::make_shared<MoveRightCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Left, std::make_shared<MoveLeftCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Up, std::make_shared<MoveUpCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Down, std::make_shared<MoveDownCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<PlaySoundCommand>(), ButtonBehaviour::DownThisFrame);

	InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::RightArrow, std::make_shared<MoveRightCommand>(pepperComp), ButtonBehaviour::Pressed);
	InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::LeftArrow, std::make_shared<MoveLeftCommand>(pepperComp), ButtonBehaviour::Pressed);
	InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::UpArrow, std::make_shared<MoveUpCommand>(pepperComp), ButtonBehaviour::Pressed);
	InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::DownArrow, std::make_shared<MoveDownCommand>(pepperComp), ButtonBehaviour::Pressed);

	scene.Add(mrPepper);

#pragma endregion

#pragma region BurgerTest

	auto pIngridient = std::make_shared<GameObject>();
	//BTEngine::GameObject* pIngridientPart = new BTEngine::GameObject();
	auto pTransform = pIngridient->AddComponent<TransformComponent>();
	pTransform->Translate(400.f, 200.0f);
	//pTransform->SetSize(3.0f, 3.0f);

	auto inComp = pIngridient->AddComponent<IngredientComponent>();
	inComp->InitializeIngredientParts(&scene);
	scene.Add(pIngridient);


#pragma endregion

#pragma region level

	auto level = std::make_shared<GameObject>();
	auto levelComp = level->AddComponent<LevelComponent>();
	levelComp->SetPhysicsManager(physics);
	levelComp->SetLevelPath("..\\data\\Level1.txt");
	levelComp->ParseLevelFile();

	for (const std::shared_ptr<GameObject> obj : levelComp->GetGameObjects()) {
		scene.Add(obj);
	}

#pragma endregion


}

void BurgerEngine::Cleanup()
{
	BTEngine::Minigin::Cleanup();
}

void BurgerEngine::Run()
{
	BTEngine::Minigin::Run();

}
