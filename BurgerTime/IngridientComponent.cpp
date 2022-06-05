#include "IngridientComponent.h"
#include "TransformComponent.h"
#include "AnimationComponent.h"
#include "RenderComponent.h"
//#include "CollisionComponent.h"
#include "BoxCollider.h"
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

void IngredientComponent::InitializeIngredientParts(BTEngine::Scene* scene) {

	assert(scene != nullptr);

	float partOffset = (31.f / m_AmountOfParts) * 2.0f;

	for (size_t i = 0; i < m_AmountOfParts; i++)
	{
		auto pIngredientPart = std::make_shared<BTEngine::GameObject>();
		auto pTransform = pIngredientPart->AddComponent<TransformComponent>();
		pTransform->SetPosition((partOffset + 16.0f) * i, 0.0f);
		pTransform->SetSize(partOffset, 16.0f);
		pIngredientPart->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");
		GetGameObject()->AddChild(pIngredientPart.get());

		AnimationComponent* pAnimationComp = pIngredientPart->AddComponent<AnimationComponent>();

		Animation ingredientAnimation{};
		ingredientAnimation.SetSpriteSheet("spritesheet.png");
		ingredientAnimation.m_AmountOfColumns = 0;
		ingredientAnimation.m_AmountOfRows = 0;

		ingredientAnimation.m_CellWidth = int(partOffset);
		ingredientAnimation.m_CellHeigth = 7;
		ingredientAnimation.m_AnimationFramesPerSecond = 0;
		ingredientAnimation.m_AnchorPoint = IVector2{ 113 + int((partOffset * i)), 50};

		pAnimationComp->AddAnimation(0, ingredientAnimation);
		pIngredientPart->AddComponent<RigidBodyComponent>()->SetRigidBodyType(RigidType::Dynamic);
		pIngredientPart->AddComponent<BoxCollider>()->SetBoundingBox({0.0f, 0.0f, partOffset, 16.0f});

		m_IngredientParts.emplace_back(pIngredientPart->AddComponent<IngredientPartComponent>());

		scene->Add(pIngredientPart);
	}
}

void IngredientComponent::Update()
{
	auto it = std::find_if(m_IngredientParts.begin(), m_IngredientParts.end(), [](IngredientPartComponent* ingredientPart) {

		return !ingredientPart->IsSteppedOn();

		});

	// If we can't find a part that is not stepped on the ingredient is fully pressed
	if (it == m_IngredientParts.end()) {

		GetGameObject()->GetComponent<TransformComponent>()->Translate(0.0f, 20.0f * TimeManager::GetDeltaTime());

	}
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