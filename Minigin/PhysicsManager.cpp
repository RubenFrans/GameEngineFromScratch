#include "MiniginPCH.h"
#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{

}

void PhysicsManager::DetectCollision() const
{
	for (size_t i = 0; i < m_CollisionComponents.size(); i++)
	{

		if (i + 1 >= m_CollisionComponents.size())
			return;

		const Rect& r1 = m_CollisionComponents[i]->GetBoudingBox();
		const Rect& r2 = m_CollisionComponents[i+1]->GetBoudingBox();

		// If one rectangle is on left side of the other
		if ((r1.x + r1.w) < r2.x || (r2.x + r2.w) < r1.x)
		{
			continue;
		}

		// If one rectangle is under the other
		if (r1.y > (r2.y + r2.h) || r2.y > (r1.y + r1.h))
		{
			continue;
		}

		m_CollisionComponents[i]->TriggerOverlap();
		m_CollisionComponents[i+1]->TriggerOverlap();
	}

}

void PhysicsManager::Update()
{
}

void PhysicsManager::FixedUpdate()
{
	DetectCollision();
}

void PhysicsManager::Render() const
{
}

void PhysicsManager::Initialize()
{
}

void PhysicsManager::AddPhysicsBody(CollisionComponent* pCollisionComp) {
	m_CollisionComponents.emplace_back(pCollisionComp);
}
