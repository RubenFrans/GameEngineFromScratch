#pragma once
#include "GameObject.h"
#include "BaseComponent.h"
#include "PhysicsManager.h"
#include <memory>
#include "Scene.h"

//class BTEngine::Scene;

class IngredientComponent
	: public BaseComponent
{
public:
	IngredientComponent(BTEngine::GameObject* pOwner);
	virtual ~IngredientComponent();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;

	//void SetPhysicsManager(std::shared_ptr<PhysicsManager> phyicsManager);
	//void SetInitializationScene(BTEngine::Scene* scene);


	std::vector<std::shared_ptr<BTEngine::GameObject>>& GetParts() { return m_IngredientParts; }
	void InitializeIngredientParts(BTEngine::Scene* scene, PhysicsManager* physics);

private:
	
	std::vector<std::shared_ptr<BTEngine::GameObject>> m_IngredientParts;

	size_t m_AmountOfParts;
	//std::shared_ptr<PhysicsManager> m_pPhyiscs;
	//BTEngine::Scene* m_pScene;
};

