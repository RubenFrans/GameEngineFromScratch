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


    void SetEnablePhysicsDebug(bool debugEnabled);

private:

    void DetectCollision();


    struct Collision {
        int collisionIndex1;
        int collisionIndex2;

        bool operator==(const Collision& rhs) {

            if(collisionIndex1 == rhs.collisionIndex1 && collisionIndex2 == rhs.collisionIndex2) {
                return true;
            }
            else if (collisionIndex1 == rhs.collisionIndex2 && collisionIndex2 == rhs.collisionIndex1) {
                return true;
            }
            return false;
        }

    };

    std::vector<Collision> m_Collisions;
    std::vector<Collision> m_PrevCollisions;
   

    bool m_Detect{ false };
    bool m_PhysicsDebugEnabled;
	std::vector<CollisionComponent*> m_CollisionComponents;
};

