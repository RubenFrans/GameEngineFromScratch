#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class EnemyComponent :
    public BaseComponent, public Subject
{
public:
	EnemyComponent(dae::GameObject* pOwner);
	virtual ~EnemyComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	void Die();

private:

};

