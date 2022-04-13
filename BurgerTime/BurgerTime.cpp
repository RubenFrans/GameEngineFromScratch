// BurgerTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vld.h>
#include "Minigin.h"

int main(int, char*[]) {

	//if (!SteamAPI_Init())
	//{
	//	std::cerr << "Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed)." << std::endl;
	//	return 1;
	//}
	//else
	//	std::cout << "Successfully initialized steam." << std::endl;

	//SteamUserStats()->ClearAchievement("ACH_WIN_ONE_GAME");
	dae::Minigin engine;
	engine.Run();

	//SteamAPI_Shutdown();
    return 0;
}

