#pragma once
#include "Subject.h"

class AchievementComponent
	: public BaseComponent, public Observer
{
public:
	AchievementComponent(dae::GameObject* pOwner);
	virtual ~AchievementComponent() = default;
	virtual void Update();
	virtual void FixedUpdate();
	void onNotify(const BaseComponent& comp, Event event) override;
private:

};

