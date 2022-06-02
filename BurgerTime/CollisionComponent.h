#pragma once
#include "BaseComponent.h"
#include "structs.h"
#include <functional>

class CollisionComponent :
    public BaseComponent
{
public:
    
    CollisionComponent(BTEngine::GameObject* m_pOwner);
    ~CollisionComponent() override = default;
    CollisionComponent(const CollisionComponent& other) = delete;
    CollisionComponent(CollisionComponent&& other) noexcept = delete;
    CollisionComponent& operator=(const CollisionComponent& other) = delete;
    CollisionComponent& operator=(CollisionComponent&& other) noexcept = delete;

    void Update() override;
    void FixedUpdate() override;
    void Initialize() override;

    void SetBoundingBox(const Rect& boundingBox);
    void SetTrigger(bool isTrigger);


    void TriggerOverlap();

    void SetOnTriggerCallback(const std::function<void()>& callBack);

private:
    Rect m_BoundingBox;
    bool m_IsTrigger;
    std::function<void()> m_OnTriggerCallback;
};