#pragma once
#include "BaseComponent.h"
#include "Subject.h"

class TransformComponent;
class AnimationComponent;


enum class MrPepperState : int {
	down = 0,
	up = 1,
	left = 2,
	right = 3
};

class MrPepperComponent
	: public BaseComponent, public Subject
{
public:
	MrPepperComponent(BTEngine::GameObject* pOwner);
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

	MrPepperState m_State;

};

