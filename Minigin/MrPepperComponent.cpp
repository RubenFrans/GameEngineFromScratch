#include "MiniginPCH.h"
#include "MrPepperComponent.h"

MrPepperComponent::MrPepperComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_IsDead{ false }
{

}

void MrPepperComponent::Update()
{

}

void MrPepperComponent::FixedUpdate()
{

}

void MrPepperComponent::Die() {
	m_IsDead = true;
	Notify(*this, Event::PLAYER_DIE);
}
