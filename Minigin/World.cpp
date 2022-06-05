#include "MiniginPCH.h"
#include "World.h"
#include "b2_body.h"
#include "TimeManager.h"

World::World()
	: m_Gravity{ 0.0f, 10.0f }
{
	m_pWorld = new b2World(m_Gravity);
}

World::~World()
{
	delete m_pWorld;
}

void World::Initialize()
{

}

void World::Update()
{

}

void World::FixedUpdate()
{
	m_pWorld->Step(0.02f, 6, 2);
}

b2Body* World::CreateBody(const FVector2& initialPosition)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2{ initialPosition.x, initialPosition.y };
	return m_pWorld->CreateBody(&bodyDef);
}
