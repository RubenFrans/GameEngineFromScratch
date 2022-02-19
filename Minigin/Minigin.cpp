#include "MiniginPCH.h"
#include "Minigin.h"
#include <thread>
#include "InputManager.h"
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
		640,
		480,
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
		->SetText("It'ss working!!!")
		->SetFont(font);

	fpsCounter->AddComponent<RenderComponent>();
	fpsCounter->AddComponent<TransformComponent>();
	
	scene.Add(fpsCounter);
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
		auto& input = InputManager::GetInstance();

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

			doContinue = input.ProcessInput();

			while (lag >= Time::GetMsPerFixedFrame()) {
				// For fixedUpdate
				sceneManager.FixedUpdate();
				lag -= Time::GetMsPerFixedFrame();
			}

			sceneManager.Update();
			renderer.Render();

			// What if sleep time goes lowe than 0?
			const auto sleepTime = currentTime + std::chrono::milliseconds(Time::GetMsPerFrame())
					- std::chrono::high_resolution_clock::now();

			std::cout << sleepTime << std::endl;
			this_thread::sleep_for(sleepTime);

		}
	}

	Cleanup();
}
