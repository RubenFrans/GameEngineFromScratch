#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class BurgerComponent :
    public BaseComponent, public Subject
{
public:
	BurgerComponent(BTEngine::GameObject* pOwner);
	virtual ~BurgerComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	void DropBurger();
private:

};

