#include "MiniginPCH.h"
#include "Minigin.h"
#include <thread>
#include "InputManager2.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include <chrono>
#include "Time.h"

#include "TextComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "FPSComponent.h"
#include "RGBColor.h"
#include "ImGuiPlotComponent.h"
#include "MrPepperComponent.h"
#include "LivesComponent.h"

using namespace std;

void PrintSDLVersion()
{
	SDL_version compiled{};
	SDL_version linked{};

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("We compiled against SDL version %d.%d.%d ...\n",
		compiled.major, compiled.minor, compiled.patch);
	printf("We are linking against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);
}

void dae::Minigin::Initialize()
{
	PrintSDLVersion();
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{

	auto& scene = SceneManager::GetInstance().CreateScene("Demo");
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto go = std::make_shared<GameObject>();
	go->AddComponent<RenderComponent>()->SetTexture("background.jpg");
	go->AddComponent<TransformComponent>();
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->AddComponent<RenderComponent>()->SetTexture("logo.png");
	go->AddComponent<TransformComponent>()->SetTransform(216.f, 180.f);
	scene.Add(go);

	// Title
	auto title = std::make_shared<GameObject>();
	title->AddComponent<TextComponent>()
		->SetFont(font)
		->SetText("Programming 4 Assignment");
	title->AddComponent<RenderComponent>();
	title->AddComponent<TransformComponent>()->SetTransform(80.f, 20.f);

	scene.Add(title);

	// Fps counter
	auto fpsCounter = std::make_shared<GameObject>();
	fpsCounter->AddComponent<TextComponent>()
		->SetText("Missing FPS component")
		->SetFont(font)
		->SetColor(RGBColor{150, 150, 0});

	fpsCounter->AddComponent<RenderComponent>();
	fpsCounter->AddComponent<TransformComponent>();
	fpsCounter->AddComponent<FPSComponent>();

	//auto plot1 = std::make_shared<GameObject>();

	//plot1->AddComponent<ImGuiPlotComponent>();

	//scene.Add(plot1);
	
	// Line to test removal of Components, fps counter will not display fps but "missing component"
	//fpsCounter->RemoveComponent<FPSComponent>();

	// Adding fpsCounter as child to title
	//title->AddChild(fpsCounter.get());
	// uncomment to check if removal of child also works
	//title->RemoveChild(0);

	// Seeting parent of FpsCounter directly to title
	//fpsCounter->SetParent(title.get());

	scene.Add(fpsCounter);


	// p1 lives
	auto p1Lives = std::make_shared<GameObject>();
	p1Lives->AddComponent<RenderComponent>();
	p1Lives->AddComponent<TransformComponent>()->SetTransform(0.0f, 100.0f);
	p1Lives->AddComponent<TextComponent>()
		->SetText("Lives: ")
		->SetFont(font)
		->SetColor(RGBColor{ 150, 150, 0 });
	LivesComponent* p1LivesComponent = p1Lives->AddComponent<LivesComponent>();
	
	scene.Add(p1Lives);



	// Mr pepper
	auto mrPepper = std::make_shared<GameObject>();
	auto pepperComp = mrPepper->AddComponent<MrPepperComponent>();
	pepperComp->AddObserver(p1LivesComponent);
	scene.Add(mrPepper);

	InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<DieCommand>(pepperComp), ButtonBehaviour::DownThisFrame, 0);

	// p2 lives
	auto p2Lives = std::make_shared<GameObject>();
	p2Lives->AddComponent<RenderComponent>();
	p2Lives->AddComponent<TransformComponent>()->SetTransform(0.0f, 200.0f);
	p2Lives->AddComponent<TextComponent>()
		->SetText("Lives: ")
		->SetFont(font)
		->SetColor(RGBColor{ 150, 150, 0 });
	LivesComponent* p2LivesComponent = p2Lives->AddComponent<LivesComponent>();

	scene.Add(p2Lives);

	// Mr pepper player 2
	auto mrPepper2 = std::make_shared<GameObject>();
	auto pepperComp2 = mrPepper->AddComponent<MrPepperComponent>();
	pepperComp2->AddObserver(p2LivesComponent);
	scene.Add(mrPepper2);

	InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<DieCommand>(pepperComp2), ButtonBehaviour::DownThisFrame, 1);
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{

	
	Initialize();
	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		//auto& input = InputManager::GetInstance();

		// todo: this update loop could use some work.
		bool doContinue = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		float lag = 0.0f;
		while (doContinue)
		{
			const auto currentTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
			
			lastTime = currentTime;
			lag += deltaTime;

			Time::SetDeltaTime(deltaTime);
			Time::SetTotalTime(Time::GetTotalTime() + deltaTime);

			doContinue = InputManager::GetInstance().ProcessInput();

			while (lag >= Time::GetMsPerFixedFrame()) {
				// For fixedUpdate
				sceneManager.FixedUpdate();
				lag -= Time::GetMsPerFixedFrame();
			}

			sceneManager.Update();
			renderer.Render();

			const auto sleepTime = currentTime + std::chrono::milliseconds(Time::GetMsPerFrame())
					- std::chrono::high_resolution_clock::now();

			this_thread::sleep_for(sleepTime);

		}
	}

	Cleanup();
}
