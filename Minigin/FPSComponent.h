#pragma once
#include "BaseComponent.h"
class FPSComponent :
    public BaseComponent
{
public:
	FPSComponent(dae::GameObject* pOwner);
	virtual ~FPSComponent() = default;
	virtual void Update();
	virtual void FixedUpdate();
	float GetFPS();
private:
	float m_CurrentFps;
};

