#pragma once
class AudioClipImpl;

class AudioClip
{
public:
	AudioClip(const std::string& path);
	~AudioClip();
	void Load();
	bool Play();
	void SetVolume();
	int GetVolume();

	bool IsLoaded() const;
private:
	AudioClipImpl* m_pAudioClipImpl;
};

