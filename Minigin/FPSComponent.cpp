#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "TimeManager.h"
#include "GameObject.h"
#include "TextComponent.h"

FPSComponent::FPSComponent(dae::GameObject* pOwner)
    : BaseComponent{ pOwner }, m_CurrentFps{}
{
}

void FPSComponent::Update()
{
    m_CurrentFps = 1.0f / TimeManager::GetDeltaTime();

    TextComponent* tc = GetGameObject()->GetComponent<TextComponent>();

    if (!tc)
        return;

    tc->SetText(std::to_string(int(m_CurrentFps)) + " FPS");

}

void FPSComponent::FixedUpdate()
{
}

float FPSComponent::GetFPS()
{
    return m_CurrentFps;
}
