#pragma once

#include "ColliderComponent.h"

class CircleCollider
	: public ColliderComponent
{
public:
	CircleCollider(BTEngine::GameObject* pOwner);
	~CircleCollider() = default;
	CircleCollider(const CircleCollider& other) = delete;
	CircleCollider(CircleCollider&& other) noexcept = delete;
	CircleCollider& operator=(const CircleCollider& other) = delete;
	CircleCollider& operator=(CircleCollider&& other) noexcept = delete;

	void Initialize() override;
	void Update() override;
	void FixedUpdate() override;
	void Render() const override;

	void SetRadius(float radius);

private:
	float m_Radius;
};

