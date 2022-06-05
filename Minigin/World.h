#pragma once
#include "b2_world.h"
#include "SceneObject.h"
#include "structs.h"
class World
{
public:
    World();
    ~World();
    World(const World& other) = delete;
    World(World&& other) noexcept = delete;
    World& operator=(const World& other) = delete;
    World& operator=(World&& other) noexcept = delete;

    void Update();
    void Initialize();
    void FixedUpdate();
    void RenderDebugBodies();
    b2Body* CreateBody(const FVector2& initialPos);

private:

    struct WorldBody {
        b2Body* pBody;
        Rect boundingBox;
    };

    b2Vec2 m_Gravity;
    b2World* m_pWorld;

};

