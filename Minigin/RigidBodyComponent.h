#pragma once
#include "BaseComponent.h"
#include "structs.h"
#include <functional>

class b2Body;
class b2Fixture;
class BTEngine::GameObject;
class TransformComponent;
struct CollisionInfo;
class ColliderComponent;

enum class RigidType {
    Static = 0,
    Kinematic = 1,
    Dynamic = 2
};

class RigidBodyComponent
    : public BaseComponent
{
public:
    RigidBodyComponent(BTEngine::GameObject* pOwner);
    ~RigidBodyComponent();
    RigidBodyComponent(const RigidBodyComponent& other) = delete;
    RigidBodyComponent(RigidBodyComponent&& other) noexcept = delete;
    RigidBodyComponent& operator=(const RigidBodyComponent& other) = delete;
    RigidBodyComponent& operator=(RigidBodyComponent&& other) noexcept = delete;

    void InitializeRigidbody();

    void Initialize() override;
    void Update() override;
    void FixedUpdate() override;

    void SetInitialPosition(const FVector2& initialPos);
    b2Body* GetBody() const;

    void SetRigidBodyType(RigidType type);
    void SetVelocity(const FVector2& velocity);
    void AddForce(const FVector2& velocity);
    void SetPosition(const FVector2& position);
    FVector2 GetPosition() const;

    b2Fixture* AddFixtureToBody(const Rect& boundingBox, ColliderComponent* pCollisionInfo);
    b2Fixture* AddFixtureToBody(float radius, ColliderComponent* pCollisionInfo);

private:
	b2Body* m_pRigidBody;
    FVector2 m_InitialPos;
    RigidType m_CurrentRigidType;
    TransformComponent* m_pTransformComponent;
};

