#pragma once
#pragma comment(lib, "xinput.lib")
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Xinput.h>
#include <map>
#include <vector>
#include "Command.h"
#include <memory>
#include "XboxController.h"
#include "Command.h"
#include "ControllerButtons.h"
#include "Singleton.h"

class InputManager : public BTEngine::Singleton<InputManager>
{
public:
	InputManager();
	~InputManager();
	bool ProcessInput();

	void AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);
	void AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv, int controllerId);

	void AddKeyboardMapping(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);

private:
	void CheckPressed();
	void CheckDownThisFrame() const;
	void CheckUpThisFrame() const;

	const int m_AmountOfControllers{ 4 };
	std::vector<XboxController*> m_Controllers{};

};
