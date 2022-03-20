#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class EnemyComponent :
    public BaseComponent, public Subject
{
public:
	EnemyComponent(dae::GameObject* pOwner);
	virtual ~EnemyComponent() = default;
	virtual void Update();
	virtual void FixedUpdate();
	void Die();

private:

};

