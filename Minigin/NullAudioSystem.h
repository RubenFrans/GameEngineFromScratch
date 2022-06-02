#pragma once
#include "AudioSystem.h"
class NullAudioSystem final :
    public AudioSystem
{
public:
    NullAudioSystem() = default;
    ~NullAudioSystem() override = default;
    NullAudioSystem(const NullAudioSystem& other) = delete;
    NullAudioSystem(NullAudioSystem&& other) noexcept = delete;
    NullAudioSystem& operator=(const NullAudioSystem& other) = delete;
    NullAudioSystem& operator=(NullAudioSystem&& other) noexcept = delete;

    virtual void Initialize() {};
    virtual void PlayAudioClip(int) {};
    virtual void StopAudioClip() {};
    virtual void LoadAudioClip(int, const std::string&, bool) {};

protected:
    virtual void ProcessAudioQueue() {}

private:

};

