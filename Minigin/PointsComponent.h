#pragma once
#include "BaseComponent.h"
#include "Observer.h"
#include "Subject.h"

class PointsComponent :
    public BaseComponent, public Observer, public Subject
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
	int GetPoints() const;

private:
	int m_AmountOfPoints;
};

