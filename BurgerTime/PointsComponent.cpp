#include "MiniginPCH.h"
#include "PointsComponent.h"
#include "GameObject.h"
#include "TextComponent.h"

PointsComponent::PointsComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_AmountOfPoints{ 0 }
{

}

void PointsComponent::Update()
{
}

void PointsComponent::FixedUpdate()
{
}

void PointsComponent::onNotify(const BaseComponent&, Event event)
{
	switch (event)
	{
	case Event::PLAYER_DIE:

		break;
	case Event::ENEMY_DIE:
		AddPoints(20);
		break;
	case Event::BURGER_DROP:
		AddPoints(10);
		break;
	default:
		break;
	}
}

void PointsComponent::AddPoints(int amount)
{
	m_AmountOfPoints += amount;
	Notify(*this, Event::POINTS_ADDED);
	UpdateTextComponent();
}

void PointsComponent::SubtractPoints(int amount)
{
	m_AmountOfPoints -= amount;
	Notify(*this, Event::POINTS_SUBTRACTED);
	UpdateTextComponent();
}

void PointsComponent::UpdateTextComponent()
{
	GetGameObject()->GetComponent<TextComponent>()->SetText("Points: " + std::to_string(m_AmountOfPoints));
}

int PointsComponent::GetPoints() const
{
	return m_AmountOfPoints;
}


