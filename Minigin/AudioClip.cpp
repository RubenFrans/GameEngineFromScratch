#include "MiniginPCH.h"
#include "AudioClip.h"
#include "SDL_mixer.h"

class AudioClip::AudioClipImpl {

public:
    AudioClipImpl(const std::string& path)
        : m_Path{ path }
        , m_pChunk{ nullptr }
    {
    }

    ~AudioClipImpl()
    {
        if (m_pChunk) {
            Mix_FreeChunk(m_pChunk);
        }
    }

    void Load()
    {
        std::string fullPath = "..\\data\\";
        fullPath.append(m_Path);
        m_pChunk = Mix_LoadWAV(fullPath.c_str());

        if (m_pChunk == nullptr)
            std::cout << "Failed to load audio file" << std::endl;
    }

    bool Play()
    {
        if (!IsLoaded())
            return false;

        int channel{ Mix_PlayChannel(-1, m_pChunk, 0) };
        return channel;
    }

    void SetVolume()
    {
    }

    int GetVolume()
    {
        return 0;
    }

    bool IsLoaded() const
    {
        if (m_pChunk)
            return true;
        else
            return false;
    }

private:
    Mix_Chunk* m_pChunk;
    std::string m_Path;
};


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
