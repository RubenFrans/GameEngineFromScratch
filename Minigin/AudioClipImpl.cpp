#include "MiniginPCH.h"
#include "AudioClipImpl.h"

AudioClipImpl::AudioClipImpl(const std::string& path)
    : m_Path{ path }
    , m_pChunk{ nullptr }
{

}

AudioClipImpl::~AudioClipImpl()
{
    if (m_pChunk) {
        Mix_FreeChunk(m_pChunk);
    }
}

void AudioClipImpl::Load()
{
    std::string fullPath = "..\\data\\";
    fullPath.append(m_Path);
    m_pChunk = Mix_LoadWAV(fullPath.c_str());

    if (m_pChunk == nullptr)
        std::cout << "Failed to load audio file" << std::endl;
}

bool AudioClipImpl::Play()
{
    if (!IsLoaded())
        return false;

    int channel{ Mix_PlayChannel(-1, m_pChunk, 0) };
    return channel;
}

void AudioClipImpl::SetVolume()
{
}

int AudioClipImpl::GetVolume()
{
    return 0;
}

bool AudioClipImpl::IsLoaded() const
{
    if (m_pChunk)
        return true;
    else
        return false;
}
