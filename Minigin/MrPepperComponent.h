#pragma once
#include "BaseComponent.h"
#include "Subject.h"
class MrPepperComponent
	: public BaseComponent, public Subject
{
public:
	MrPepperComponent(dae::GameObject* pOwner);
	virtual ~MrPepperComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	void Die();
private:
	bool m_IsDead;
};

