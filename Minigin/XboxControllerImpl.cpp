#include "MiniginPCH.h"
#include "XboxControllerImpl.h"
#include <iostream>


XboxControllerImpl::XboxControllerImpl(const int controllerId)
    : m_ControllerId{ controllerId }
{

}

const XINPUT_STATE& XboxControllerImpl::GetControllerState() const
{
    return m_pControllerState;
}

DWORD XboxControllerImpl::UpdateControllerState()
{
    CopyMemory(&m_pPrevControllerState, &m_pControllerState, sizeof(XINPUT_STATE));
    ZeroMemory(&m_pControllerState, sizeof(XINPUT_STATE));

    DWORD result = XInputGetState(m_ControllerId, &m_pControllerState);
    auto buttonChanges = m_pControllerState.Gamepad.wButtons ^ m_pPrevControllerState.Gamepad.wButtons;
    m_ButtonsPressedThisFrame = buttonChanges & m_pControllerState.Gamepad.wButtons;
    m_ButtonsReleasedThisFrame = buttonChanges & (~m_pControllerState.Gamepad.wButtons);

    return result;
}

void XboxControllerImpl::CheckPressed()
{
    for (auto it = m_IsPressedCommands.begin(); it != m_IsPressedCommands.end(); it++) {

        XINPUT_STATE cState = GetControllerState();

        if (cState.Gamepad.wButtons & int((*it).first)) {
            std::cout << "Controller " << m_ControllerId << ": ";
            it->second->Execute();

            std::cout << " is pressed" << std::endl;
        }
    }
}

void XboxControllerImpl::CheckDownThisFrame()
{
    for (auto it = m_IsDownCommands.begin(); it != m_IsDownCommands.end(); it++) {

        auto cState = GetButtonsPressedThisFrame();

        if (cState & int((*it).first)) {
            std::cout << "Controller " << m_ControllerId << ": ";
            it->second->Execute();
            std::cout << " has gone down this frame" << std::endl;
        }
    }
}

void XboxControllerImpl::CheckUpThisFrame()
{
    for (auto it = m_IsUpCommands.begin(); it != m_IsUpCommands.end(); it++) {

        auto cState = GetButtonsReleasedThisFrame();

        if (cState & int((*it).first)) {
            std::cout << "Controller " << m_ControllerId << ": ";
            it->second->Execute();

            std::cout << " has gone up this frame" << std::endl;
        }
    }
}

int XboxControllerImpl::GetButtonsPressedThisFrame() const
{
    return m_ButtonsPressedThisFrame;
}

int XboxControllerImpl::GetButtonsReleasedThisFrame() const
{
    return m_ButtonsReleasedThisFrame;
}

void XboxControllerImpl::AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
{
    XboxControllerButton xBtn = EngineButtonToXboxButton(btn);

    ControllerCommandMap* mapToAddTo{ nullptr };

    switch (behv)
    {
    case ButtonBehaviour::Pressed:
        mapToAddTo = &m_IsPressedCommands;
        break;
    case ButtonBehaviour::DownThisFrame:
        mapToAddTo = &m_IsDownCommands;
        break;
    case ButtonBehaviour::UpThisFrame:
        mapToAddTo = &m_IsUpCommands;
        break;
    }

    mapToAddTo->insert(std::pair<XboxControllerImpl::XboxControllerButton, std::shared_ptr<Command>>{
        xBtn, command
    });
}


XboxControllerImpl::XboxControllerButton XboxControllerImpl::EngineButtonToXboxButton(ControllerButton btn) const
{
    XboxControllerButton xBtn{};
    switch (btn)
    {
    case ControllerButton::ButtonA:
        xBtn = XboxControllerButton::ButtonA;
        break;
    case ControllerButton::ButtonB:
        xBtn = XboxControllerButton::ButtonB;
        break;
    case ControllerButton::ButtonX:
        xBtn = XboxControllerButton::ButtonX;
        break;
    case ControllerButton::ButtonY:
        xBtn = XboxControllerButton::ButtonY;
        break;
    case ControllerButton::RightShoulder:
        xBtn = XboxControllerButton::RightShoulder;
        break;
    case ControllerButton::LeftShoulder:
        xBtn = XboxControllerButton::LeftShoulder;
        break;
    case ControllerButton::DPad_Left:
        xBtn = XboxControllerButton::DPad_Left;
        break;
    case ControllerButton::DPad_Right:
        xBtn = XboxControllerButton::DPad_Right;
        break;
    case ControllerButton::DPad_Up:
        xBtn = XboxControllerButton::DPad_Up;
        break;
    case ControllerButton::DPad_Down:
        xBtn = XboxControllerButton::DPad_Down;
        break;
    case ControllerButton::ButtonR3:
        xBtn = XboxControllerButton::ButtonR3;
        break;
    case ControllerButton::ButtonL3:
        xBtn = XboxControllerButton::ButtonL3;
        break;
    default:
        xBtn = XboxControllerButton::ButtonA;
        break;
    }

    return xBtn;
}
