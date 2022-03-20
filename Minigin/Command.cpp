#include "MiniginPCH.h"
#include "Command.h"
#include <iostream>
//#include "Application.h"

/*
* FIRE COMMAND
*/

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
