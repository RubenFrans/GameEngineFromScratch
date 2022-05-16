#pragma once
#include "BaseComponent.h"
#include "Observer.h"
#include "Subject.h"

class PointsComponent :
    public BaseComponent, public Observer, public Subject
{
public:
	PointsComponent(BTEngine::GameObject* pOwner);
	virtual ~PointsComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

	virtual void onNotify(const BaseComponent& component, Event event) override;

	void AddPoints(int amount);
	void SubtractPoints(int amount);
	void UpdateTextComponent();
	int GetPoints() const;

private:
	int m_AmountOfPoints;
};

