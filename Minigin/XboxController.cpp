#include "MiniginPCH.h"
#include "XboxController.h"
#include "XboxControllerImpl.h"

XboxController::XboxController(const int controllerId)
{
    m_pImpl = new XboxControllerImpl(controllerId);
}

XboxController::~XboxController()
{
    delete m_pImpl;
}

const XINPUT_STATE& XboxController::GetControllerState() const
{
    return m_pImpl->GetControllerState();
}

DWORD XboxController::UpdateControllerState()
{
    return m_pImpl->UpdateControllerState();
}

void XboxController::CheckPressed() const
{
    m_pImpl->CheckPressed();
}

void XboxController::CheckDownThisFrame() const
{
    m_pImpl->CheckDownThisFrame();
}

void XboxController::CheckUpThisFrame() const
{
    m_pImpl->CheckUpThisFrame();
}

int XboxController::GetButtonsPressedThisFrame() const
{
    return m_pImpl->GetButtonsPressedThisFrame();
}

int XboxController::GetButtonsReleasedThisFrame() const
{
    return m_pImpl->GetButtonsReleasedThisFrame();
}

void XboxController::AddControllerMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
{
    m_pImpl->AddButtonMapping(btn, command, behv);
}
