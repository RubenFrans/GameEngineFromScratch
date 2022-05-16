#include "MiniginPCH.h"
#include "BurgerComponent.h"

BurgerComponent::BurgerComponent(BTEngine::GameObject* pOwner)
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
