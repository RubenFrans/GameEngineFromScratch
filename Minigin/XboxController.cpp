#include "MiniginPCH.h"
#include "XboxController.h"
#include <map>
#include <Xinput.h>

class XboxController::XboxControllerImpl {
public:
    enum class XboxControllerButton : int
    {
        ButtonA = XINPUT_GAMEPAD_A,
        ButtonB = XINPUT_GAMEPAD_B,
        ButtonX = XINPUT_GAMEPAD_X,
        ButtonY = XINPUT_GAMEPAD_Y,
        RightShoulder = XINPUT_GAMEPAD_RIGHT_SHOULDER,
        LeftShoulder = XINPUT_GAMEPAD_LEFT_SHOULDER,
        DPad_Left = XINPUT_GAMEPAD_DPAD_LEFT,
        DPad_Right = XINPUT_GAMEPAD_DPAD_RIGHT,
        DPad_Up = XINPUT_GAMEPAD_DPAD_UP,
        DPad_Down = XINPUT_GAMEPAD_DPAD_DOWN,
        ButtonR3 = XINPUT_GAMEPAD_RIGHT_THUMB,
        ButtonL3 = XINPUT_GAMEPAD_LEFT_THUMB
    };

    XboxControllerImpl(const int controllerId)
        : m_ControllerId{ controllerId }
    {

    }

    const XINPUT_STATE& GetControllerState() const
    {
        return m_pControllerState;
    }

    DWORD UpdateControllerState()
    {
        CopyMemory(&m_pPrevControllerState, &m_pControllerState, sizeof(XINPUT_STATE));
        ZeroMemory(&m_pControllerState, sizeof(XINPUT_STATE));

        DWORD result = XInputGetState(m_ControllerId, &m_pControllerState);
        auto buttonChanges = m_pControllerState.Gamepad.wButtons ^ m_pPrevControllerState.Gamepad.wButtons;
        m_ButtonsPressedThisFrame = buttonChanges & m_pControllerState.Gamepad.wButtons;
        m_ButtonsReleasedThisFrame = buttonChanges & (~m_pControllerState.Gamepad.wButtons);

        return result;
    }

    void CheckPressed()
    {
        for (auto it = m_IsPressedCommands.begin(); it != m_IsPressedCommands.end(); it++) {

            XINPUT_STATE cState = GetControllerState();

            if (cState.Gamepad.wButtons & int((*it).first)) {
                //std::cout << "Controller " << m_ControllerId << ": ";
                it->second->Execute();

                //std::cout << " is pressed" << std::endl;
            }
        }
    }

    void CheckDownThisFrame()
    {
        for (auto it = m_IsDownCommands.begin(); it != m_IsDownCommands.end(); it++) {

            auto cState = GetButtonsPressedThisFrame();

            if (cState & int((*it).first)) {
                //std::cout << "Controller " << m_ControllerId << ": ";
                it->second->Execute();
                //std::cout << " has gone down this frame" << std::endl;
            }
        }
    }

    void CheckUpThisFrame()
    {
        for (auto it = m_IsUpCommands.begin(); it != m_IsUpCommands.end(); it++) {

            auto cState = GetButtonsReleasedThisFrame();

            if (cState & int((*it).first)) {
               // std::cout << "Controller " << m_ControllerId << ": ";
                it->second->Execute();

                //std::cout << " has gone up this frame" << std::endl;
            }
        }
    }

    int GetButtonsPressedThisFrame() const
    {
        return m_ButtonsPressedThisFrame;
    }

    int GetButtonsReleasedThisFrame() const
    {
        return m_ButtonsReleasedThisFrame;
    }

    void AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
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


    XboxControllerButton EngineButtonToXboxButton(ControllerButton btn) const
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

    private:
        const int m_ControllerId;
        XINPUT_STATE m_pControllerState;
        XINPUT_STATE m_pPrevControllerState;
        int m_ButtonsPressedThisFrame;
        int m_ButtonsReleasedThisFrame;

        using Controllerkey = std::map<unsigned, XboxControllerImpl::XboxControllerButton>;
        using ControllerCommandMap = std::map <XboxControllerImpl::XboxControllerButton, std::shared_ptr<Command>>;

        ControllerCommandMap m_IsDownCommands{};
        ControllerCommandMap m_IsUpCommands{};
        ControllerCommandMap m_IsPressedCommands{};

};

XboxController::XboxController(const int controllerId)
{
    m_pImpl = new XboxControllerImpl(controllerId);
}

XboxController::~XboxController()
{
    delete m_pImpl;
}

// Remove
//const XINPUT_STATE& XboxController::GetControllerState() const
//{
//    return m_pImpl->GetControllerState();
//}

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
