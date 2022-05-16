#include "MiniginPCH.h"
#include "Keyboard.h"
#include <unordered_map>
#include "imgui_impl_sdl.h"

class BTEngine::Keyboard::KeyboardImpl {

public:
	KeyboardImpl() 
		: m_IsDownCommands{}
		, m_IsUpCommands{}
		, m_IsPressedCommands{}
	{

	}
	enum class KeyboardSDLMapping {
		UpArrow = SDL_SCANCODE_UP,
		DownArrow = SDL_SCANCODE_DOWN,
		LeftArrow = SDL_SCANCODE_LEFT,
		RightArrow = SDL_SCANCODE_RIGHT,
		Space = SDL_SCANCODE_SPACE,
		Enter = SDL_SCANCODE_RETURN
	};


	void CheckKeysPressed() {
		KeyboardButton btn{};
		const Uint8* state = SDL_GetKeyboardState(NULL);

		for (auto& button : m_IsPressedCommands) {
			if (state[int(KeyboardButtonToSDL(btn))]) {
				button.second->Execute();
			}
		}
	}

	void AddKeyboardMappingImpl(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv) {
		
		switch (behv) {
		case ButtonBehaviour::DownThisFrame:
			m_IsDownCommands.insert({ btn, command });
			break;
		case ButtonBehaviour::UpThisFrame:
			m_IsUpCommands.insert({ btn, command });
			break;
		case ButtonBehaviour::Pressed:
			m_IsPressedCommands.insert({ btn, command });
			break;
		}
	}

	KeyboardButton SDLToKeyboardButton(KeyboardSDLMapping sdlButton) {
		switch (sdlButton)
		{
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::UpArrow:
			return KeyboardButton::UpArrow;
			break;
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::DownArrow:
			return KeyboardButton::DownArrow;
			break;
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::LeftArrow:
			return KeyboardButton::LeftArrow;
			break;
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::RightArrow:
			return KeyboardButton::RightArrow;
			break;
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::Space:
			return KeyboardButton::Space;
			break;
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::Enter:
			return KeyboardButton::Enter;
			break;
		default:
			return KeyboardButton::UpArrow;
			break;
		}
	}

	KeyboardSDLMapping KeyboardButtonToSDL(KeyboardButton keyboardButton) {
		switch (keyboardButton)
		{
		case KeyboardButton::UpArrow:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::UpArrow;
			break;
		case  KeyboardButton::DownArrow:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::DownArrow;
			break;
		case KeyboardButton::LeftArrow:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::LeftArrow;
			break;
		case KeyboardButton::RightArrow:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::RightArrow;
			break;
		case KeyboardButton::Space:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::Space;
			break;
		case KeyboardButton::Enter:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::Enter;
			break;
		default:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::RightArrow;
			break;
		}
	}

private:
	std::unordered_map<KeyboardButton, std::shared_ptr<Command>> m_IsDownCommands;
	std::unordered_map<KeyboardButton, std::shared_ptr<Command>> m_IsUpCommands;
	std::unordered_map<KeyboardButton, std::shared_ptr<Command>> m_IsPressedCommands;

};

BTEngine::Keyboard::Keyboard() 
	: m_pKeyboardImpl{ new KeyboardImpl{} }
{

}

BTEngine::Keyboard::~Keyboard() {
	delete m_pKeyboardImpl;
}


void BTEngine::Keyboard::CheckPressed() {
	m_pKeyboardImpl->CheckKeysPressed();
}

void BTEngine::Keyboard::AddKeyboardMapping(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
{
	m_pKeyboardImpl->AddKeyboardMappingImpl(btn, command, behv);
}
