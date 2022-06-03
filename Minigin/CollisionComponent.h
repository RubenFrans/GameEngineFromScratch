#pragma once
#include "BaseComponent.h"
#include "structs.h"
#include <functional>
#include "structs.h"

class TransformComponent;

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

    const Rect& GetBoudingBox() const;


    void TriggerOverlap(BTEngine::GameObject* triggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action);

    void SetOnTriggerCallback(const std::function<void(BTEngine::GameObject* triggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action)>& callBack);

private:
    Rect m_OriginalBoundingBox;
    Rect m_BoundingBox;
    bool m_IsTrigger;
    std::function<void(BTEngine::GameObject* triggerObject, BTEngine::GameObject* pOtherObject, TriggerAction action)> m_OnTriggerCallback;
    TransformComponent* m_pTransformComponent;
};