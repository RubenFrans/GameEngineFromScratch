#pragma once
#include "BaseComponent.h"
#include "structs.h"

class b2Body;
class BTEngine::GameObject;
class TransformComponent;

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

private:
	b2Body* m_pRigidBody;
    FVector2 m_InitialPos;
    TransformComponent* m_pTransformComponent;
};

