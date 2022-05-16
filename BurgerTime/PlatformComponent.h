#pragma once
#include "BaseComponent.h"

class BTEngine::GameObject;
class AnimationComponent;

class PlatformComponent final
	: public BaseComponent
{
public:
	PlatformComponent(BTEngine::GameObject* pOwner);
	virtual ~PlatformComponent();

	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

private:

	void InitializeAnimations();

	AnimationComponent* m_pAnimationComponent;
};

