#pragma once
#include "Minigin.h"
class BurgerEngine :
    public BTEngine::Minigin
{
public:
	void Initialize() override;
	void LoadGame() override;
	void Cleanup() override;
	void Run() override;
private:

};

