#pragma once
//#include "MrPepperComponent.h"
//#include "BurgerComponent.h"
//#include "EnemyComponent.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
private:

};


class WinGameCommand
	: public Command
{
public:
	WinGameCommand()
	{
	}

	virtual ~WinGameCommand() = default;
	virtual void Execute() override;
private:
};

class ToggleDebugCommand
	: public Command
{
public:
	ToggleDebugCommand() = default;
	virtual ~ToggleDebugCommand() = default;
	virtual void Execute() override;
private:

};

