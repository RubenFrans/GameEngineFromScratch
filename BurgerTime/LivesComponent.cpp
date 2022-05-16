#include "MiniginPCH.h"
#include "LivesComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

LivesComponent::LivesComponent(BTEngine::GameObject* pOwner)
    : BaseComponent{ pOwner }, m_CurrentAmountOfLives{ 3 }
{
}

void LivesComponent::Update()
{

}

void LivesComponent::FixedUpdate()
{

}

void LivesComponent::Initialize()
{
}

void LivesComponent::SetAmountOfLives(int amountOfLives)
{
    m_CurrentAmountOfLives = amountOfLives;
}

int LivesComponent::GetAmountOfLivesLeft() const
{
    return m_CurrentAmountOfLives;
}

void LivesComponent::onNotify(const BaseComponent&, Event event)
{
    if (event == Event::PLAYER_DIE) {
        --m_CurrentAmountOfLives;
        GetGameObject()->GetComponent<TextComponent>()->SetText("Lives: " + std::to_string(m_CurrentAmountOfLives));
    }
}
