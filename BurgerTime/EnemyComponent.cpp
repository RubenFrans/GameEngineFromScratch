#include "MiniginPCH.h"
#include "EnemyComponent.h"

EnemyComponent::EnemyComponent(BTEngine::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void EnemyComponent::Update()
{
}

void EnemyComponent::FixedUpdate()
{
}

void EnemyComponent::Initialize()
{
}

void EnemyComponent::Die()
{
	Notify(*this, Event::ENEMY_DIE);
}
