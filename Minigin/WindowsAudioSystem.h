#pragma once
#include "AudioSystem.h"

class WindowsAudioSystemImpl;

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
private:
    virtual void ProcessAudioQueue() override;
    WindowsAudioSystemImpl* m_pAudioSystemImpl;

};

