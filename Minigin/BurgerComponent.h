#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class BurgerComponent :
    public BaseComponent, public Subject
{
public:
	BurgerComponent(dae::GameObject* pOwner);
	virtual ~BurgerComponent() = default;
	virtual void Update();
	virtual void FixedUpdate();
	void DropBurger();
private:

};

