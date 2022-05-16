//#pragma once
//#pragma comment(lib, "xinput.lib")
//
//#define WIN32_LEAN_AND_MEAN
//
//#include <Windows.h>
//#include <Xinput.h>
//#include <memory>
//#include <map>
//#include <vector>
//#include "Command.h"
//#include "ControllerButtons.h"
//
//class XboxControllerImpl
//{
//	enum class XboxControllerButton : int
//	{
//		ButtonA = XINPUT_GAMEPAD_A,
//		ButtonB = XINPUT_GAMEPAD_B,
//		ButtonX = XINPUT_GAMEPAD_X,
//		ButtonY = XINPUT_GAMEPAD_Y,
//		RightShoulder = XINPUT_GAMEPAD_RIGHT_SHOULDER,
//		LeftShoulder = XINPUT_GAMEPAD_LEFT_SHOULDER,
//		DPad_Left = XINPUT_GAMEPAD_DPAD_LEFT,
//		DPad_Right = XINPUT_GAMEPAD_DPAD_RIGHT,
//		DPad_Up = XINPUT_GAMEPAD_DPAD_UP,
//		DPad_Down = XINPUT_GAMEPAD_DPAD_DOWN,
//		ButtonR3 = XINPUT_GAMEPAD_RIGHT_THUMB,
//		ButtonL3 = XINPUT_GAMEPAD_LEFT_THUMB
//	};
//
//public:
//	XboxControllerImpl(const int controllerId);
//	const XINPUT_STATE& GetControllerState() const;
//	DWORD UpdateControllerState();
//
//	void CheckPressed();
//	void CheckDownThisFrame();
//	void CheckUpThisFrame();
//
//	int GetButtonsPressedThisFrame() const;
//	int GetButtonsReleasedThisFrame() const;
//
//	void AddButtonMapping(ControllerButton btn, std::shared_ptr<Command>, ButtonBehaviour behv);
//
//private:
//	const int m_ControllerId;
//	XINPUT_STATE m_pControllerState;
//	XINPUT_STATE m_pPrevControllerState;
//	int m_ButtonsPressedThisFrame;
//	int m_ButtonsReleasedThisFrame;
//
//	using Controllerkey = std::map<unsigned, XboxControllerImpl::XboxControllerButton>;
//	using ControllerCommandMap = std::map <XboxControllerImpl::XboxControllerButton, std::shared_ptr<Command>>;
//
//	ControllerCommandMap m_IsDownCommands{};
//	ControllerCommandMap m_IsUpCommands{};
//	ControllerCommandMap m_IsPressedCommands{};
//
//	XboxControllerButton EngineButtonToXboxButton(ControllerButton btn) const;
//
//};
//
//
