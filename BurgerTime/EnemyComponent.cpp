#include "MiniginPCH.h"
#include "EnemyComponent.h"

EnemyComponent::EnemyComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void EnemyComponent::Update()
{
}

void EnemyComponent::FixedUpdate()
{
}

void EnemyComponent::Die()
{
	Notify(*this, Event::ENEMY_DIE);
}
