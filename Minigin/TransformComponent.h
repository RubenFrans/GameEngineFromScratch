#pragma once
#include "BaseComponent.h"
#include "Transform.h"

class TransformComponent :
    public BaseComponent
{
public:
	TransformComponent(dae::GameObject* pOwner);
	virtual ~TransformComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

	void SetTransform(float x, float y);
	void SetTransform(const dae::Transform& transform);
	const dae::Transform& GetTransform() const;
private:
	dae::Transform m_Transform;
};

