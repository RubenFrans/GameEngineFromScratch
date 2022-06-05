#pragma once
#include "ColliderComponent.h"
class BoxCollider :
    public ColliderComponent
{
public:
    BoxCollider(BTEngine::GameObject* pOwner);
    ~BoxCollider() = default;
    BoxCollider(const BoxCollider& other) = delete;
    BoxCollider(BoxCollider&& other) noexcept = delete;
    BoxCollider& operator=(const BoxCollider& other) = delete;
    BoxCollider& operator=(BoxCollider&& other) noexcept = delete;


    void Initialize() override;
    void Update() override;
    void FixedUpdate() override;
    void Render() const override;
    void SetBoundingBox(const Rect& boundingBox);

private:
    Rect m_BoundingBox;
    Rect m_FullLengthBoudingBox;
};

