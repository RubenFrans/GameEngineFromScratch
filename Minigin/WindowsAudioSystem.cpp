#include "MiniginPCH.h"
#include "WindowsAudioSystem.h"
#include "WindowsAudioSystemImpl.h"
#include "SDL_mixer.h"
#include <thread>
#include "AudioClip.h"

WindowsAudioSystem::WindowsAudioSystem()
	: m_pAudioSystemImpl{ new WindowsAudioSystemImpl{} }
{
}

WindowsAudioSystem::~WindowsAudioSystem()
{
	delete m_pAudioSystemImpl;
}

void WindowsAudioSystem::Initialize() {

	m_pAudioSystemImpl->Initialize();

}

void WindowsAudioSystem::PlayAudioClip(int id)
{
	m_pAudioSystemImpl->PlayAudioClip(id);
}

void WindowsAudioSystem::StopAudioClip()
{
	std::cout << "Stopped audio clip" << std::endl;
}

void WindowsAudioSystem::LoadAudioClip(int id, const std::string& path, bool storedContinuous)
{
	m_pAudioSystemImpl->LoadAudioClip(id, path, storedContinuous);
}

void WindowsAudioSystem::ProcessAudioQueue() {
	// handled internally in the implementation
}