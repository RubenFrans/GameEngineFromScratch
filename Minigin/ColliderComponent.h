#pragma once
#include "BaseComponent.h"
#include "structs.h"

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

    void SetBoundingBox(const Rect& boundingBox);

private:
    b2Fixture* m_pFixture;
    Rect m_BoundingBox;
};

