#pragma once
#include "BaseComponent.h"
#include "structs.h"

// No forward declaration for this type because otherwise this header file would not be self sufficient
#include "RigidBodyComponent.h"


class BTEngine::GameObject;
class b2Fixture;

enum class ColliderType {
    BoxCollider,
    CircleCollider
};

class ColliderComponent
	: public BaseComponent
{
public:
	ColliderComponent(BTEngine::GameObject* pOwner);
    ~ColliderComponent() = default;
    ColliderComponent(const ColliderComponent& other) = delete;
    ColliderComponent(ColliderComponent&& other) noexcept = delete;
    ColliderComponent& operator=(const ColliderComponent& other) = delete;
    ColliderComponent& operator=(ColliderComponent&& other) noexcept = delete;
    
    void Initialize() override;
    void Update() override;
    void FixedUpdate() override;
    void Render() const override;

protected:
    b2Fixture* m_pFixture;
    RigidBodyComponent* m_pRigidBodyComponent;

private:
    ColliderType m_ColliderType;
};

