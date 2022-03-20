#pragma once
#include "BaseComponent.h"
#include "Observer.h"

class PointsComponent :
    public BaseComponent, public Observer
{
public:
	PointsComponent(dae::GameObject* pOwner);
	virtual ~PointsComponent() = default;
	virtual void Update();
	virtual void FixedUpdate();

	virtual void onNotify(const BaseComponent& component, Event event) override;

	void AddPoints(int amount);
	void SubtractPoints(int amount);
	void UpdateTextComponent();

private:
	int m_AmountOfPoints;
};

