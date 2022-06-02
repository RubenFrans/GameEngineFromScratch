#include "MiniginPCH.h"
#include "AudioSystemLocator.h"

AudioSystem* AudioSystemLocator::m_AudioSystemService{ nullptr };
NullAudioSystem AudioSystemLocator::m_NullService{};