#pragma once
#include "BaseComponent.h"
#include "Observer.h"

class LivesComponent :
    public BaseComponent, public Observer
{
public:
	LivesComponent(dae::GameObject* pOwner);
	virtual ~LivesComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

	void SetAmountOfLives(int amountOfLives);
	int GetAmountOfLivesLeft() const;

	virtual void onNotify(const BaseComponent& entity, Event event);

private:
	int m_CurrentAmountOfLives;
};

