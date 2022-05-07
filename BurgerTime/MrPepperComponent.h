#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class TransformComponent;
class AnimationComponent;

class MrPepperComponent
	: public BaseComponent, public Subject
{
public:
	MrPepperComponent(dae::GameObject* pOwner);
	virtual ~MrPepperComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void Die();
private:
	
	void InitializeAnimations();
	
	bool m_IsDead;
	float m_HorizontalSpeed;
	float m_VerticalSpeed;
	TransformComponent* m_pTransformComponent;
	AnimationComponent* m_pAnimationComponent;

};

