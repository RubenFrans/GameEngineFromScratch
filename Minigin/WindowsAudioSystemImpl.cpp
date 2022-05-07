#include "MiniginPCH.h"
#include "WindowsAudioSystemImpl.h"
#include "SDL_mixer.h"
#include <thread>
#include "AudioClip.h"

WindowsAudioSystemImpl::WindowsAudioSystemImpl()
	: m_ContinuouslyLoadedAudio{}, m_SoundQueue{}
	, m_AudioQueueEmpty{ true }
	, m_KillAudioThread{ false }
	, m{}
	, m_ProcessAudioCondition{}
{
}

WindowsAudioSystemImpl::~WindowsAudioSystemImpl()
{
	for (auto& audioEntry : m_ContinuouslyLoadedAudio) {
		delete audioEntry.second;
	}

	m_KillAudioThread = true;
	m_ProcessAudioCondition.notify_all();
	m_SoundThread.join();
}

void WindowsAudioSystemImpl::Initialize()
{
	int result = 0;
	int flags = MIX_INIT_MP3;

	if (SDL_Init(SDL_INIT_AUDIO)) {
		std::cout << "Failed to initialize SDL audio" << std::endl;
	}

	if (flags != (result = Mix_Init(flags))) {
		printf("Could not initialize mixer (result: %d).\n", result);
		printf("Mix_Init: %s\n", Mix_GetError());
	}

	// Open mixer with audio settings
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);

	m_SoundThread = std::thread(&WindowsAudioSystemImpl::ProcessAudioQueue, this);
}

void WindowsAudioSystemImpl::PlayAudioClip(int id)
{
	// Make sure to lock the queue to make it thread safe, its very unsafe now
	m_SoundQueue.push(m_ContinuouslyLoadedAudio.at(id));
	m_ProcessAudioCondition.notify_all();
}

void WindowsAudioSystemImpl::StopAudioClip()
{
	std::cout << "Stopped audio clip" << std::endl;
}

void WindowsAudioSystemImpl::LoadAudioClip(int id, const std::string& path, bool storedContinuous)
{
	std::cout << "Loading audio clip" << std::endl;
	AudioClip* audioClip{ new AudioClip{ path } };
	m_ContinuouslyLoadedAudio.insert(std::pair<int, AudioClip*>{id, audioClip});

	// Preload audio if stored continuous
	if (storedContinuous)
		audioClip->Load();
}

void WindowsAudioSystemImpl::ProcessAudioQueue()
{
	// Runs on seperate thread processing audio requests
	while (!m_KillAudioThread) {
		std::unique_lock<std::mutex> lock(m);

		// Wait untile queue is not empty
		m_ProcessAudioCondition.wait(lock, [&] {
			return m_SoundQueue.size() > 0 || m_KillAudioThread;
			});

		// If the audio thread should be killed skip condition variable and break the loop
		if (m_KillAudioThread)
			break;

		// Make sure to only lock the soundquuee popping not the entire loading and playing otherwise we have the same problem with waiting until a sound is loaded and played

		AudioClip* sound = m_SoundQueue.front();
		m_SoundQueue.pop();
		// unlock the lock here
		m_ProcessAudioCondition.notify_all();

		std::cout << "Play audio file" << std::endl;

		if (!sound->IsLoaded()) {
			sound->Load();
		}

		if (sound->IsLoaded()) {
			sound->Play();
		}
	}
}
