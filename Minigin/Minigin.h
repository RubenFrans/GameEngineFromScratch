#pragma once

struct SDL_Window;
namespace BTEngine
{
	class Minigin
	{
	public:
		virtual void Initialize();
		virtual void LoadGame() const;
		virtual void Cleanup();
		virtual void Run();
	private:
		SDL_Window* m_Window{};
		bool m_DoContinue = true;
	};
}