#pragma once
#include "AudioSystem.h"
#include <unordered_map>
#include <queue>
#include <condition_variable>
#include <mutex>

class AudioClip;

class WindowsAudioSystem final :
    public AudioSystem
{
public:
    WindowsAudioSystem();
    virtual ~WindowsAudioSystem();
    virtual void Initialize() override;
    virtual void PlayAudioClip(int id) override;
    virtual void StopAudioClip() override;
    virtual void LoadAudioClip(int id, const std::string& path, bool storedContinuous) override;
    virtual void ProcessAudioQueue() override;
private:
    std::unordered_map<int, AudioClip*> m_ContinuouslyLoadedAudio;
    std::queue<AudioClip*> m_SoundQueue;

    std::thread m_SoundThread;

    std::mutex m;
    std::condition_variable m_ProcessAudioCondition;
    bool m_KillAudioThread;
    bool m_AudioQueueEmpty;
};

