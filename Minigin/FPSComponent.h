#pragma once
#include "BaseComponent.h"
class FPSComponent :
    public BaseComponent
{
public:
	FPSComponent(BTEngine::GameObject* pOwner);
	virtual ~FPSComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	float GetFPS();
private:
	float m_CurrentFps;
};

