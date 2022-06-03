#pragma once
#include "BaseComponent.h"
#include "Transform.h"

class TransformComponent :
    public BaseComponent
{
public:
	TransformComponent(BTEngine::GameObject* pOwner);
	virtual ~TransformComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;

	void SetPosition(float x, float y);
	void SetSize(float x, float y);
	void SetTransform(const BTEngine::Transform& transform);
	const BTEngine::Transform& GetTransform() const;
	const BTEngine::Transform& GetWorldTransform() const;

	void Translate(float x, float y);

private:
	void UpdateWorldTransform();
	BTEngine::Transform m_LocalTransform;
	BTEngine::Transform m_WorldTransform;
};

