#pragma once
#include "BaseComponent.h"
#include "structs.h"
//#include "b2_body.h"

class b2Body;
class b2Fixture;
class BTEngine::GameObject;
class TransformComponent;

enum class RigidType {
    //Static = b2BodyType::b2_staticBody,
    //Kinematic = b2BodyType::b2_kinematicBody
    //Dynamic = b2BodyType::b2_dynamicBody,
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
    b2Fixture* AddFixtureToBody(const Rect& boundingBox);

private:
	b2Body* m_pRigidBody;
    FVector2 m_InitialPos;
    RigidType m_CurrentRigidType;
    TransformComponent* m_pTransformComponent;
};

