#include "MiniginPCH.h"
#include "World.h"
#include "b2_body.h"
#include "b2_fixture.h"
#include "TimeManager.h"
#include "Renderer.h"
#include "ContactListener.h"

World::World()
	: m_Gravity{ 0.0f, 100.0f }
	, m_pWorld{ nullptr }
	, m_pContactListener{ nullptr }
{
	m_pWorld = new b2World(m_Gravity);
	m_pContactListener = new ContactListener();
	m_pWorld->SetContactListener(m_pContactListener);
}

World::~World()
{
	delete m_pWorld;
	delete m_pContactListener;
}

void World::Initialize()
{

}

void World::Update()
{

}

void World::FixedUpdate()
{
	m_pWorld->Step(0.05f, 6, 2);
	
}

b2Body* World::CreateBody(const FVector2& initialPosition)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2{ initialPosition.x, initialPosition.y };
	return m_pWorld->CreateBody(&bodyDef);
}
