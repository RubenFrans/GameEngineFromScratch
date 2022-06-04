#include "IngridientComponent.h"
#include "TransformComponent.h"
#include "AnimationComponent.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"
#include "IngredientPartComponent.h"
#include "Scene.h"

enum class IngredientType {
	BunTop,
	BunBottom,
	Patty,
	Cheese,
	Lettuce,
	Tomato
};

IngredientComponent::IngredientComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner)
	, m_AmountOfParts{ 4 }
{

}

IngredientComponent::~IngredientComponent()
{
	//for (size_t i = 0; i < m_IngredientParts.size(); i++)
	//{
	//	delete m_IngredientParts.at(i);
	//}
}

void IngredientComponent::Initialize()
{
	//InitializeIngredientParts();
}

void IngredientComponent::InitializeIngredientParts(BTEngine::Scene* scene, PhysicsManager* physics) {

	assert(scene != nullptr);
	assert(physics != nullptr);

	float partOffset = (31.f / m_AmountOfParts) * 2.0f;

	for (size_t i = 0; i < m_AmountOfParts; i++)
	{
		auto pIngredientPart = std::make_shared<BTEngine::GameObject>();
		auto pTransform = pIngredientPart->AddComponent<TransformComponent>();
		pTransform->Translate(partOffset * i, 0.0f);
		pTransform->SetSize(2.0f, 2.0f);
		pIngredientPart->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");
		GetGameObject()->AddChild(pIngredientPart.get());

		auto collisionComp = pIngredientPart->AddComponent<CollisionComponent>();
		collisionComp->SetBoundingBox(Rect{ .0f, .0f , 31.f / m_AmountOfParts, 7.0f });
		physics->AddPhysicsBody(collisionComp);

		AnimationComponent* pAnimationComp = pIngredientPart->AddComponent<AnimationComponent>();

		Animation ingredientAnimation{};
		ingredientAnimation.SetSpriteSheet("spritesheet.png");
		ingredientAnimation.m_AmountOfColumns = 0;
		ingredientAnimation.m_AmountOfRows = 0;

		ingredientAnimation.m_CellWidth = int(partOffset);
		ingredientAnimation.m_CellHeigth = 7;
		ingredientAnimation.m_AnimationFramesPerSecond = 0;
		ingredientAnimation.m_AnchorPoint = IVector2{ 113 + int((partOffset * i)), 50};
		//ingredientAnimation.m_AnchorPoint = IVector2{ 0, 0 };

		pAnimationComp->AddAnimation(0, ingredientAnimation);
		//pAnimationComp->SetPlayAnimation(0);

		pIngredientPart->AddComponent<IngredientPartComponent>();

		m_IngredientParts.emplace_back(pIngredientPart);

		scene->Add(pIngredientPart);
	}
}

void IngredientComponent::Update()
{

}

void IngredientComponent::FixedUpdate()
{

}

//void IngredientComponent::SetPhysicsManager(std::shared_ptr<PhysicsManager> manager) {
//	m_pPhyiscs = manager;
//}
//
//void IngredientComponent::SetInitializationScene(BTEngine::Scene* scene) {
//	m_pScene = scene;
//}