#pragma once
#include "Commands.h"
#include "AudioSystemLocator.h"
#include <iostream>

void FireCommand::Execute()
{
	std::cout << "Command: Fire";
}

void DieCommand::Execute()
{
	m_MrPepper->Die();
}

void BurgerDropCommand::Execute()
{
	m_pBurgerComponent->DropBurger();
}

void EnemyDieCommand::Execute()
{
	m_pEnemyComponent->Die();
}

void PlaySoundCommand::Execute() {
	AudioSystemLocator::GetAudio().PlayAudioClip(0);
}

void MoveRightCommand::Execute()
{
	m_pMrPepperComponent->MoveRight();
}

void MoveLeftCommand::Execute()
{
	m_pMrPepperComponent->MoveLeft();
}

void MoveUpCommand::Execute()
{
		m_pMrPepperComponent->MoveUp();
	if (m_pMrPepperComponent->m_IsOnLadder) {
	}
}

void MoveDownCommand::Execute()
{
		m_pMrPepperComponent->MoveDown();
	if (m_pMrPepperComponent->m_IsOnLadder) {
	}
}
