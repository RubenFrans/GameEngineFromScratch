#include "MiniginPCH.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include <algorithm>
#include "structs.h"

PhysicsManager::PhysicsManager()
	: m_CollisionComponents{}
	, m_PhysicsDebugEnabled{ false }
	, m_Collisions{}
	, m_PrevCollisions{}
{

}

/// <summary>
/// Replace with quadtree implementation in the future
/// </summary>
void PhysicsManager::DetectCollision()
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


			Collision collision{ int(i), int(j) };
			TriggerAction action{};
			m_Collisions.emplace_back(collision);
			
			// If collision happend previous frame as well we set the collision action to stay
			auto it = std::find_if(m_PrevCollisions.begin(), m_PrevCollisions.end(), [&](const Collision& prevCollision) {
					
					if(prevCollision == collision){
						
						action = TriggerAction::Stay;
						return true;

					}

					return false;
				});

			// If the collision did not happend last frame we set the colllision action to Enter because it happend this frame for the first time
			if (it == m_PrevCollisions.end()) {
				action = TriggerAction::Enter;
			}


			BTEngine::GameObject* pTriggerObject{ m_CollisionComponents[i]->GetGameObject() };
			BTEngine::GameObject* pOtherObject{ m_CollisionComponents[j]->GetGameObject() };

			m_CollisionComponents[i]->TriggerOverlap(pTriggerObject, pOtherObject, action);
			m_CollisionComponents[j]->TriggerOverlap(pOtherObject, pTriggerObject, action);

		}
	}


	// Check all collisions that happend this frame
	

	std::for_each(m_PrevCollisions.begin(), m_PrevCollisions.end(), [&](const Collision& prevCollision) {

		auto it2 = std::find_if(m_Collisions.begin(), m_Collisions.end(), [&](const Collision& collision) {

				Collision col{prevCollision};

				if (collision == col) {
					return true;
				}

				return false;

			});

			if (it2 == m_Collisions.end()) {

				BTEngine::GameObject* pTriggerObject{ m_CollisionComponents[prevCollision.collisionIndex1]->GetGameObject() };
				BTEngine::GameObject* pOtherObject{ m_CollisionComponents[prevCollision.collisionIndex2]->GetGameObject() };

				m_CollisionComponents[prevCollision.collisionIndex1]->TriggerOverlap(pTriggerObject, pOtherObject, TriggerAction::Leave);
				m_CollisionComponents[prevCollision.collisionIndex2]->TriggerOverlap(pTriggerObject, pOtherObject, TriggerAction::Leave);

			}
		});


	// Each collision that is not present in the new collisions that is present in the previous frame collisions gets triggerd with the leave action

	// TODO Refactor to use switching pointers of collisionbuffers to circumvent copy of collisionBuffer
	m_PrevCollisions = m_Collisions;
	m_Collisions.clear();
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
	if (m_Detect) {
		DetectCollision();

	}

	if (!m_Detect) {
		m_Detect = true;
	}
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
