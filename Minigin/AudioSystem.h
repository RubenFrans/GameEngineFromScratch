#pragma once
#include <string>

class AudioSystem {
public:
	AudioSystem() = default;
	virtual ~AudioSystem() = default;
	virtual void Initialize() = 0;
	virtual void PlayAudioClip(int id) = 0;
	virtual void StopAudioClip() = 0;
	virtual void LoadAudioClip(int id, const std::string& path, bool storedContinuous) = 0;

protected:
	virtual void ProcessAudioQueue() = 0;
private:

};