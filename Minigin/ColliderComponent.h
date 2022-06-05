#pragma once
#include "BaseComponent.h"
#include "structs.h"
#include <functional>

// No forward declaration for this type because otherwise this header file would not be self sufficient
#include "RigidBodyComponent.h"


class BTEngine::GameObject;
class b2Fixture;

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
    
    void SetCollisionCallback(const std::function<void(BTEngine::GameObject* pCollidedObject, TriggerAction action)>& callback);
    void TriggerOverlap(BTEngine::GameObject* pOtherObject, TriggerAction action);
    void SetIsSensor(bool isSensor);
    bool IsSensor() const;

protected:
    b2Fixture* m_pFixture;
    RigidBodyComponent* m_pRigidBodyComponent;
    std::function<void(BTEngine::GameObject* pCollidedGameObject, TriggerAction action)> m_OnCollisionCallback;
    bool m_IsSensor;

private:



};

