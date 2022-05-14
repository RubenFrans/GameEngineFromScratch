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

using namespace dae;

void BurgerEngine::Initialize()
{
	dae::Minigin::Initialize();
}

/*
* Loading and scene construction starts here
*/
void BurgerEngine::LoadGame() const
{
	dae::Minigin::LoadGame();
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	// Mr pepper
	auto mrPepper = std::make_shared<GameObject>();
	auto pepperComp = mrPepper->AddComponent<MrPepperComponent>();
	
	mrPepper->AddComponent<TransformComponent>()->SetSize(5, 5);
	mrPepper->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");



	mrPepper->AddComponent<AnimationComponent>();



	scene.Add(mrPepper);

	//AudioSystemLocator::GetService()->LoadAudioClip(0, "Navi - Hey.mp3", true);
	//AudioSystemLocator::GetService()->PlayAudioClip(0);

	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Right, std::make_shared<MoveRightCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Left, std::make_shared<MoveLeftCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Up, std::make_shared<MoveUpCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
	InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Down, std::make_shared<MoveDownCommand>(pepperComp), ButtonBehaviour::Pressed, 0);


	//auto go = std::make_shared<GameObject>();
	//go->AddComponent<RenderComponent>()->SetTexture("background.jpg");
	//go->AddComponent<TransformComponent>();
	//scene.Add(go);

	//go = std::make_shared<GameObject>();
	//go->AddComponent<RenderComponent>()->SetTexture("logo.png");
	//go->AddComponent<TransformComponent>()->SetTransform(216.f, 180.f);
	//scene.Add(go);

	//// Title
	//auto title = std::make_shared<GameObject>();
	//title->AddComponent<TextComponent>()
	//	->SetFont(font)
	//	->SetText("Programming 4 Assignment");
	//title->AddComponent<RenderComponent>();
	//title->AddComponent<TransformComponent>()->SetTransform(80.f, 20.f);

	//scene.Add(title);

	//// Fps counter
	//auto fpsCounter = std::make_shared<GameObject>();
	//fpsCounter->AddComponent<TextComponent>()
	//	->SetText("Missing FPS component")
	//	->SetFont(font)
	//	->SetColor(RGBColor{ 150, 150, 0 });

	//// p1 lives
	//auto p1Lives = std::make_shared<GameObject>();
	//p1Lives->AddComponent<RenderComponent>();
	//p1Lives->AddComponent<TransformComponent>()->SetTransform(0.0f, 100.0f);
	//p1Lives->AddComponent<TextComponent>()
	//	->SetText("Lives: 3")
	//	->SetFont(font)
	//	->SetColor(RGBColor{ 150, 150, 0 });
	//LivesComponent* p1LivesComponent = p1Lives->AddComponent<LivesComponent>();

	//scene.Add(p1Lives);



	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<DieCommand>(pepperComp), ButtonBehaviour::DownThisFrame, 0);

	//// p2 lives
	//auto p2Lives = std::make_shared<GameObject>();
	//p2Lives->AddComponent<RenderComponent>();
	//p2Lives->AddComponent<TransformComponent>()->SetTransform(0.0f, 300.0f);
	//p2Lives->AddComponent<TextComponent>()
	//	->SetText("Lives: 3")
	//	->SetFont(font)
	//	->SetColor(RGBColor{ 150, 150, 0 });
	//LivesComponent* p2LivesComponent = p2Lives->AddComponent<LivesComponent>();

	//scene.Add(p2Lives);

	//// Mr pepper player 2
	//auto mrPepper2 = std::make_shared<GameObject>();
	//auto pepperComp2 = mrPepper->AddComponent<MrPepperComponent>();
	//pepperComp2->AddObserver(p2LivesComponent);
	//scene.Add(mrPepper2);

	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<DieCommand>(pepperComp2), ButtonBehaviour::DownThisFrame, 1);

	//// Achievment system
	//auto achievementSystem = std::make_shared<GameObject>();
	//auto achievementComp = achievementSystem->AddComponent<AchievementComponent>();

	//scene.Add(achievementSystem);

	//// Points player 1
	//auto p1Points = std::make_shared<GameObject>();
	//p1Points->AddComponent<TextComponent>()
	//	->SetText("Points: 0")
	//	->SetFont(font)
	//	->SetColor(RGBColor{ 0, 150, 0 });
	//p1Points->AddComponent<TransformComponent>()
	//	->SetTransform(0.0f, 200.0f);
	//p1Points->AddComponent<RenderComponent>();
	//auto p1PointComp = p1Points->AddComponent<PointsComponent>();
	//p1PointComp->AddObserver(achievementComp);
	//scene.Add(p1Points);


	//// Points player 2
	//auto p2Points = std::make_shared<GameObject>();
	//p2Points->AddComponent<TextComponent>()
	//	->SetText("Points: 0")
	//	->SetFont(font)
	//	->SetColor(RGBColor{ 0, 150, 0 });
	//p2Points->AddComponent<TransformComponent>()
	//	->SetTransform(0.0f, 400.0f);
	//p2Points->AddComponent<RenderComponent>();
	//auto p2PointComp = p2Points->AddComponent<PointsComponent>();
	//p2PointComp->AddObserver(achievementComp);
	//scene.Add(p2Points);

	//// Burger 
	//auto burger = std::make_shared<GameObject>();
	//auto burgerComp = burger->AddComponent<BurgerComponent>();
	//burgerComp->AddObserver(p1PointComp);
	//scene.Add(burger);

	//// Burger2
	//auto burger2 = std::make_shared<GameObject>();
	//auto burgerComp2 = burger2->AddComponent<BurgerComponent>();
	//burgerComp2->AddObserver(p2PointComp);
	//scene.Add(burger2);


	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonB, std::make_shared<BurgerDropCommand>(burgerComp), ButtonBehaviour::DownThisFrame, 0);
	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonB, std::make_shared<BurgerDropCommand>(burgerComp2), ButtonBehaviour::DownThisFrame, 1);

	//// Enemy
	//auto enemy = std::make_shared<GameObject>();
	//auto enemyComp = enemy->AddComponent<EnemyComponent>();
	//enemyComp->AddObserver(p1PointComp);
	//scene.Add(enemy);

	//auto enemy2 = std::make_shared<GameObject>();
	//auto enemyComp2 = enemy2->AddComponent<EnemyComponent>();
	//enemyComp2->AddObserver(p2PointComp);
	//scene.Add(enemy2);

	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonY, std::make_shared<EnemyDieCommand>(enemyComp), ButtonBehaviour::DownThisFrame, 0);
	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonY, std::make_shared<EnemyDieCommand>(enemyComp2), ButtonBehaviour::DownThisFrame, 1);

	//InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonX, std::make_shared<WinGameCommand>(), ButtonBehaviour::DownThisFrame, 0);


}

void BurgerEngine::Cleanup()
{
	dae::Minigin::Cleanup();
}

void BurgerEngine::Run()
{
	dae::Minigin::Run();

}
