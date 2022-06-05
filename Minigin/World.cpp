#include "MiniginPCH.h"
#include "World.h"
#include "b2_body.h"

World::World()
	: m_Gravity{ 0.0f, -10.0f }
{
	m_pWorld = new b2World(m_Gravity);
}

World::~World()
{

}

void World::Initialize()
{

}

void World::Update()
{

}

void World::FixedUpdate()
{

}

b2Body* World::CreateBody(const FVector2& initialPosition)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2{ initialPosition.x, initialPosition.y };
	return m_pWorld->CreateBody(&bodyDef);

}
