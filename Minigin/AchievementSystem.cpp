#include "MiniginPCH.h"
#include "AchievementSystem.h"
#include "PointsComponent.h"
#include <steam_api.h>

AchievementComponent::AchievementComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void AchievementComponent::Update()
{
}

void AchievementComponent::FixedUpdate()
{
}

void AchievementComponent::onNotify(const BaseComponent& comp, Event event)
{
	if (event == Event::POINTS_ADDED) {
		
		if (static_cast<const PointsComponent&>(comp).GetPoints() >= 500) {
			SteamUserStats()->SetAchievement("ACH_WIN_ONE_GAME");
			SteamUserStats()->StoreStats();
		}
	}
}
