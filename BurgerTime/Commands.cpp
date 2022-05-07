#include "Commands.h"
#include "AudioSystemLocator.h"
#include <iostream>

void FireCommand::Execute()
{
	std::cout << "Command: Fire";
}

/*
* DUCK COMMAND
*/

void DuckCommand::Execute()
{
	std::cout << "Command: Duck";
}

/*
* JUMP COMMAND
*/
void JumpCommand::Execute()
{
	std::cout << "Jump";
}

/*
* FART COMMAND
*/

void FartCommand::Execute()
{
	std::cout << "Fart";
}


/*
* EXIT COMMAND
*/
//void ExitCommand::Execute()
//{
//	Application::quitApplication = true;
//}

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
	AudioSystemLocator::GetService()->PlayAudioClip(0);
}

void MoveRightCommand::Execute()
{
	m_pMrPepperComponent->MoveLeft();
}

void MoveLeftCommand::Execute()
{
	m_pMrPepperComponent->MoveRight();
}

void MoveUpCommand::Execute()
{
	m_pMrPepperComponent->MoveUp();
}

void MoveDownCommand::Execute()
{
	m_pMrPepperComponent->MoveDown();
}
