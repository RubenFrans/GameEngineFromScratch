#include "MiniginPCH.h"
#include "InputManager2.h"
#include <iostream>
#include "imgui_impl_sdl.h"


InputManager::InputManager()
{
    for (int i = 0; i < m_AmountOfControllers; i++)
    {
        m_Controllers.push_back(new XboxController(i));
    }
}

InputManager::~InputManager() {

    for (XboxController* controller : m_Controllers) {

        delete controller;
    }
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

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return false;
        }
        if (e.type == SDL_KEYDOWN) {

        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {

        }

        ImGui_ImplSDL2_ProcessEvent(&e);

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

