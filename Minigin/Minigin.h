#pragma once

struct SDL_Window;

class AudioSystem;

namespace BTEngine
{
	class Minigin
	{
	public:
		virtual void Initialize();
		virtual void LoadGame();
		virtual void Cleanup();
		virtual void Run();
	private:
		SDL_Window* m_Window{};
		AudioSystem* m_pAudioSystem;
		bool m_DoContinue = true;
	};
}