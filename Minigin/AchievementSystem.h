#pragma once
#include "Subject.h"

class AchievementComponent
	: public BaseComponent, public Observer
{
public:
	AchievementComponent(BTEngine::GameObject* pOwner);
	virtual ~AchievementComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	void onNotify(const BaseComponent& comp, Event event) override;
private:

};

