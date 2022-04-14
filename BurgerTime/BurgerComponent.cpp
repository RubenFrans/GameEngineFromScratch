#include "MiniginPCH.h"
#include "BurgerComponent.h"

BurgerComponent::BurgerComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void BurgerComponent::Update()
{
}

void BurgerComponent::FixedUpdate()
{
}

void BurgerComponent::Initialize()
{
}

void BurgerComponent::DropBurger()
{
	Notify(*this, Event::BURGER_DROP);
}
