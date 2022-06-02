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
#include "TimeManager.h"
#include <steam_api.h>

#include "TextComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "FPSComponent.h"
#include "RGBColor.h"
#include "ImGuiPlotComponent.h"

#include "SDL_mixer.h"

#include "AudioSystemLocator.h"
#include "WindowsAudioSystem.h"
#include "AudioSystem.h"

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

void PrintGameInfo() {
	//cout << "How to play (using controller): " << std::endl;
	//cout << "X / A: Kill player" << std::endl;
	//cout << "O / B: Drop burger" << std::endl;
	//cout << "Triangle / Y: Kill enemy" << std::endl;
	//cout << "Goal: Get to 500 points on either player one or player two to get the winner achievement" << std::endl;
	//

	cout << "Press the A button on your controller to play a sound" << std::endl;
}

void BTEngine::Minigin::Initialize()
{
	PrintSDLVersion();
	PrintGameInfo();
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	// Disabled steam
	//if (!SteamAPI_Init())
	//{
	//	std::cerr << "Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed)." << std::endl;
	//	m_DoContinue = false;
	//}
	//else {
	//	std::cout << "Successfully initialized steam." << std::endl;
	//	SteamUserStats()->ClearAchievement("ACH_WIN_ONE_GAME");
	//}

	Renderer::GetInstance().Init(m_Window);
}


void BTEngine::Minigin::LoadGame()
{
	/// <summary>
	/// Why initialize and provide the audio system here and not let the user of the engine library provide it himself
	/// The user should not have to worry which audiosystem gets chosen, the user just wants sound to come out of his target platform
	/// The user should be able to tell the engine, I'm building for this platform and the engine should select the appropriate system
	/// This becomes especially relevant when multiple services are at play to prevent the user from mixing service implementations designed for other target platforms
	/// </summary>

	m_pAudioSystem = new WindowsAudioSystem();
	m_pAudioSystem->Initialize();
	AudioSystemLocator::Provide(m_pAudioSystem);
}

void BTEngine::Minigin::Cleanup()
{
	delete m_pAudioSystem;
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SteamAPI_Shutdown();
	SDL_Quit();
}

void BTEngine::Minigin::Run()
{
	Initialize();
	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		sceneManager.Initialize();
		
		//auto& input = InputManager::GetInstance();

		// m_DoContinnue = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		float lag = 0.0f;
		while (m_DoContinue)
		{

			// sdl mixer test

			//int result = 0;
			//int flags = MIX_INIT_MP3;

			//if (SDL_Init(SDL_INIT_AUDIO) < 0) {
			//	printf("Failed to init SDL\n");
			//	exit(1);
			//}

			//if (flags != (result = Mix_Init(flags))) {
			//	printf("Could not initialize mixer (result: %d).\n", result);
			//	printf("Mix_Init: %s\n", Mix_GetError());
			//	exit(1);
			//}

			//Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
			//Mix_Music* music = Mix_LoadMUS("C:\\Users\\Ruben Frans\\Music\\Navi - Hey.mp3");
			//Mix_PlayMusic(music, 1);

			//while (!SDL_QuitRequested()) {
			//	SDL_Delay(250);
			//}

			//Mix_FreeMusic(music);
			////SDL_Quit();

			// end sdl mixer test

			const auto currentTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
			
			lastTime = currentTime;
			lag += deltaTime;

			TimeManager::SetDeltaTime(deltaTime);
			TimeManager::SetTotalTime(TimeManager::GetTotalTime() + deltaTime);

			m_DoContinue = InputManager::GetInstance().ProcessInput();

			while (lag >= TimeManager::GetMsPerFixedFrame()) {
				// For fixedUpdate
				sceneManager.FixedUpdate();
				lag -= TimeManager::GetMsPerFixedFrame();
			}

			sceneManager.Update();
			renderer.Render();

			SteamAPI_RunCallbacks();

			const auto sleepTime = currentTime + std::chrono::milliseconds(TimeManager::GetMsPerFrame())
					- std::chrono::high_resolution_clock::now();

			this_thread::sleep_for(sleepTime);

		}
	}

	Cleanup();
}
