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
		, m_PrevKeyboardState{ nullptr }
	{
		m_pAmountOfKeys = new int{};
		m_KeyboardState = SDL_GetKeyboardState(m_pAmountOfKeys);
		m_PrevKeyboardState = new UINT8[*m_pAmountOfKeys];
	}

	~KeyboardImpl() {
		delete m_PrevKeyboardState;
		delete m_pAmountOfKeys;
	}

	enum class KeyboardSDLMapping {
		UpArrow = SDL_SCANCODE_UP,
		DownArrow = SDL_SCANCODE_DOWN,
		LeftArrow = SDL_SCANCODE_LEFT,
		RightArrow = SDL_SCANCODE_RIGHT,
		Space = SDL_SCANCODE_SPACE,
		Enter = SDL_SCANCODE_RETURN,
		F1 = SDL_SCANCODE_F1
	};

	void CheckKeysPressed() {

		for (auto& button : m_IsPressedCommands) {
			if (m_KeyboardState[int(KeyboardButtonToSDL(button.first))]) {
				button.second->Execute();
			}
		}

		for (auto& button : m_IsDownCommands) {
			if (!m_PrevKeyboardState[int(KeyboardButtonToSDL(button.first))] && m_KeyboardState[int(KeyboardButtonToSDL(button.first))]) {
				button.second->Execute();
			}
		}

		for (auto& button : m_IsUpCommands) {
			if (m_PrevKeyboardState[int(KeyboardButtonToSDL(button.first))] && !m_KeyboardState[int(KeyboardButtonToSDL(button.first))]) {
				button.second->Execute();
			}
		}

		std::memcpy(m_PrevKeyboardState, m_KeyboardState, *m_pAmountOfKeys);

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
		case BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::F1:
			return KeyboardButton::F1;
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
		case KeyboardButton::F1:
			return BTEngine::Keyboard::KeyboardImpl::KeyboardSDLMapping::F1;
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

	UINT8* m_PrevKeyboardState;
	int* m_pAmountOfKeys;
	const UINT8* m_KeyboardState;
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
