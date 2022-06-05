#include "MiniginPCH.h"
#include "World.h"
#include "b2_body.h"
#include "b2_fixture.h"
#include "TimeManager.h"
#include "Renderer.h"


World::World()
	: m_Gravity{ 0.0f, 100.0f }
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

void World::RenderDebugBodies() {

	//b2Body* currentBody = m_pWorld->GetBodyList();

	//while(currentBody != nullptr){

	//	b2Fixture* currentFixture = currentBody->GetFixtureList();

	//	while (currentFixture != nullptr) {

	//		//b2Shape* shape = currentFixture->GetShape();
	//		
	//		BTEngine::Renderer::GetInstance().RenderRect({ currentBody->GetPosition().x, currentBody->GetPosition().y, 50.0f, 50.0f });
	//		currentFixture = currentFixture->GetNext();
	//	}
	//	currentBody = currentBody->GetNext();
	//}
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
	std::cout << bodyDef.position.x << " " << bodyDef.position.y << std::endl;
	return m_pWorld->CreateBody(&bodyDef);
}
