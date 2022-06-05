#pragma once
#include "GameObject.h"
#include "BaseComponent.h"
#include "PhysicsManager.h"
#include <memory>
#include "Scene.h"
#include <iostream>
#include "GameObject.h"
#include "TimeManager.h"

//class BTEngine::Scene;
class IngredientPartComponent;

class IngredientComponent
	: public BaseComponent
{
public:
	IngredientComponent(BTEngine::GameObject* pOwner);
	virtual ~IngredientComponent();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;

	//std::vector<std::shared_ptr<BTEngine::GameObject>>& GetParts() { return m_IngredientParts; }
	std::vector<IngredientPartComponent*>& GetParts() { return m_IngredientParts; }
	void InitializeIngredientParts(BTEngine::Scene* scene);

private:
	
	//std::vector<std::shared_ptr<BTEngine::GameObject>> m_IngredientParts;
	std::vector<IngredientPartComponent*> m_IngredientParts;
	size_t m_AmountOfParts;
	//std::shared_ptr<PhysicsManager> m_pPhyiscs;
	//BTEngine::Scene* m_pScene;
};

