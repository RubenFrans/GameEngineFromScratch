#pragma once
#include "Locator.h"
#include "AudioSystem.h"
#include "NullAudioSystem.h"

class AudioSystemLocator final
    /*public Locator<AudioSystem>*/
{
public:
    static void Initialize() { m_AudioSystemService = &m_NullService; };

    // Because the nullservice is implemented we can gurantee the user of the service to get a valid object back
    // Either a fully implemented audiosystem or the nullservice if the audiosystem was not provided correctly.
    static AudioSystem& GetAudio() {
        return *m_AudioSystemService;
    }

    static void Provide(AudioSystem* pAudioSystem) 
    {
        // if provided service is null revert back to the null service
        if (pAudioSystem == nullptr) {
            m_AudioSystemService = &m_NullService;
            
        }
        else {
            m_AudioSystemService = pAudioSystem;
        }
    }

private:
    static AudioSystem* m_AudioSystemService;
    static NullAudioSystem m_NullService;
};



