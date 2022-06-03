#include "MiniginPCH.h"
#include "PhysicsManager.h"
#include "Renderer.h"

PhysicsManager::PhysicsManager()
	: m_CollisionComponents{}
	, m_PhysicsDebugEnabled{ false }
{

}

/// <summary>
/// Replace with quadtree implementation in the future
/// </summary>
void PhysicsManager::DetectCollision() const
{
	for (size_t i = 0; i < m_CollisionComponents.size(); i++)
	{

		for (size_t j = i+1; j < m_CollisionComponents.size(); j++)
		{
			if (i + 1 >= m_CollisionComponents.size())
				return;

			const Rect& r1 = m_CollisionComponents[i]->GetBoudingBox();
			const Rect& r2 = m_CollisionComponents[j]->GetBoudingBox();

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
			m_CollisionComponents[j]->TriggerOverlap();
		}
	}
}

void PhysicsManager::SetEnablePhysicsDebug(bool debugEnabled)
{
	m_PhysicsDebugEnabled = debugEnabled;
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
#if defined _DEBUG
	//if (!m_PhysicsDebugEnabled)
	//	return;

	for (CollisionComponent* collisionComp : m_CollisionComponents) {
		BTEngine::Renderer::GetInstance().RenderRect(collisionComp->GetBoudingBox());
	}
#endif
}

void PhysicsManager::Initialize()
{
}

void PhysicsManager::AddPhysicsBody(CollisionComponent* pCollisionComp) {
	m_CollisionComponents.emplace_back(pCollisionComp);
}
