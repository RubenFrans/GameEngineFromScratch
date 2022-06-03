#pragma once
#include <vector>
#include "CollisionComponent.h"
#include "SceneObject.h"

class PhysicsManager final
    : public BTEngine::SceneObject
{
public:
	PhysicsManager();
    ~PhysicsManager() = default;
    PhysicsManager(const PhysicsManager& other) = delete;
    PhysicsManager(PhysicsManager&& other) noexcept = delete;
    PhysicsManager& operator=(const PhysicsManager& other) = delete;
    PhysicsManager& operator=(PhysicsManager&& other) noexcept = delete;

    virtual void Update();
    virtual void FixedUpdate();
    virtual void Render() const;
    virtual void Initialize();

    void AddPhysicsBody(CollisionComponent* pCollisionComponent);

    void DetectCollision() const;

    void SetEnablePhysicsDebug(bool debugEnabled);

private:

    bool m_PhysicsDebugEnabled;

	std::vector<CollisionComponent*> m_CollisionComponents;
};

