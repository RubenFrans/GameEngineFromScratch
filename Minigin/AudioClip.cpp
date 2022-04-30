#include "MiniginPCH.h"
#include "AudioClip.h"

AudioClip::AudioClip(const std::string& path)
    : m_Path{path}
{
}

AudioClip::~AudioClip()
{
    if (m_pChunk) {
        Mix_FreeChunk(m_pChunk);
    }
}

void AudioClip::Load()
{
    m_pChunk = Mix_LoadWAV(m_Path.c_str());

    if (m_pChunk == nullptr)
        std::cout << "Failed to load audio file" << std::endl;
}

bool AudioClip::Play()
{
    if (!IsLoaded())
        return false;

    int channel{ Mix_PlayChannel(-1, m_pChunk, 0) };
    return channel;
}

void AudioClip::SetVolume()
{
}

int AudioClip::GetVolume()
{
    return 0;
}

bool AudioClip::IsLoaded() const {
    if (m_pChunk)
        return true;
    else
        return false;
}
