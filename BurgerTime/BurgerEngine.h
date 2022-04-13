#pragma once
#include "Minigin.h"
class BurgerEngine :
    public dae::Minigin
{
public:
	void Initialize() override;
	void LoadGame() const override;
	void Cleanup() override;
	void Run() override;
private:

};

