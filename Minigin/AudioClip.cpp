#include "MiniginPCH.h"
#include "AudioClip.h"
#include "AudioClipImpl.h"

AudioClip::AudioClip(const std::string& path)
    : m_pAudioClipImpl{ new AudioClipImpl{ path } }
{

}

AudioClip::~AudioClip()
{
    delete m_pAudioClipImpl;
}

void AudioClip::Load()
{
    m_pAudioClipImpl->Load();
}

bool AudioClip::Play()
{
    return m_pAudioClipImpl->Play();
}

void AudioClip::SetVolume()
{
    m_pAudioClipImpl->SetVolume();
}

int AudioClip::GetVolume()
{
    return m_pAudioClipImpl->GetVolume();
}

bool AudioClip::IsLoaded() const {
    return m_pAudioClipImpl->IsLoaded();
}
