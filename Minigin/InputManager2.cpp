#include "MiniginPCH.h"
#include "InputManager2.h"
#include <iostream>
#include "Keyboard.h"
#include "imgui_impl_sdl.h"

InputManager::InputManager()
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.push_back(new XboxController(i));
    }

    m_pKeyboard = new BTEngine::Keyboard{};
}

InputManager::~InputManager() {

    for (XboxController* controller : m_Controllers) {

        delete controller;
    }

    delete m_pKeyboard;
}

bool InputManager::ProcessInput()
{
    
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
       m_Controllers.at(i)->UpdateControllerState();
    }

    CheckPressed();
    CheckDownThisFrame();
    CheckUpThisFrame();
    m_pKeyboard->CheckPressed();


    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
        switch (event.type) {
        case SDL_KEYDOWN:
            printf("Key press detected\n");
            break;

        case SDL_KEYUP:
            printf("Key release detected\n");
            break;

        case SDL_QUIT:
            return false;
            break;
        default:
            break;
        }

        ImGui_ImplSDL2_ProcessEvent(&event);
    }

    return true;
}

void InputManager::AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.at(i)->AddControllerMapping(btn, command, behv);
    }
}

void InputManager::AddButtonMapping(ControllerButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv, int controllerId)
{
    m_Controllers.at(controllerId)->AddControllerMapping(btn, command, behv);
}

void InputManager::AddKeyboardMapping(KeyboardButton btn, std::shared_ptr<Command> command, ButtonBehaviour behv)
{
    m_pKeyboard->AddKeyboardMapping(btn, command, behv);
}

void InputManager::CheckPressed() 
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.at(i)->CheckPressed();
    }
}

void InputManager::CheckDownThisFrame() const
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.at(i)->CheckDownThisFrame();
    }
}

void InputManager::CheckUpThisFrame() const
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.at(i)->CheckUpThisFrame();
    }
}

