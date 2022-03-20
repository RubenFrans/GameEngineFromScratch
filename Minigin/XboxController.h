#pragma once
#pragma comment(lib, "xinput.lib")

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <Xinput.h>
#include <memory>
#include "Command.h"
#include "ControllerButtons.h"

class XboxControllerImpl;

class XboxController {

public:

	XboxController(const int controllerId);
	~XboxController();

	const XINPUT_STATE& GetControllerState() const;
	DWORD UpdateControllerState();

	void CheckPressed() const;
	void CheckDownThisFrame() const;
	void CheckUpThisFrame() const;

	int GetButtonsPressedThisFrame() const;
	int GetButtonsReleasedThisFrame() const;

	void AddControllerMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv);

private:
	XboxControllerImpl* m_pImpl;

};

