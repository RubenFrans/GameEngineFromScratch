#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <memory>
#include "Command.h"
#include "ControllerButtons.h"



class XboxController {

public:

	XboxController(const int controllerId);
	~XboxController();

	// Remove
	//const XINPUT_STATE& GetControllerState() const;
	DWORD UpdateControllerState();

	void CheckPressed() const;
	void CheckDownThisFrame() const;
	void CheckUpThisFrame() const;

	int GetButtonsPressedThisFrame() const;
	int GetButtonsReleasedThisFrame() const;

	void AddControllerMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);
	void AddKeyboardMapping(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);

private:
	class XboxControllerImpl;
	XboxControllerImpl* m_pImpl;

};

