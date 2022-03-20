#pragma once
#include "MrPepperComponent.h"
#include "BurgerComponent.h"
#include "EnemyComponent.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
private:

};

class FireCommand 
	: public Command
{
public:
	virtual ~FireCommand() = default;
	virtual void Execute() override;
private:

};


class DuckCommand
	: public Command
{
public:
	virtual ~DuckCommand() = default;
	virtual void Execute() override;
private:

};

class FartCommand
	: public Command
{
public:
	virtual ~FartCommand() = default;
	virtual void Execute() override;
private:

};

class JumpCommand
	: public Command
{
public:
	virtual ~JumpCommand() = default;
	virtual void Execute() override;
private:

};

class ExitCommand
	: public Command
{
public:
	virtual ~ExitCommand() = default;
	virtual void Execute() override;
private:

};

class DieCommand
	: public Command
{
public:
	DieCommand(MrPepperComponent* mrPepper) 
		: m_MrPepper{mrPepper}
	{

	}

	virtual ~DieCommand() = default;
	virtual void Execute() override;
private:
	MrPepperComponent* m_MrPepper;
};

class BurgerDropCommand
	: public Command
{
public:
	BurgerDropCommand(BurgerComponent* burgerComponent)
		: m_pBurgerComponent{ burgerComponent }
	{

	}

	virtual ~BurgerDropCommand() = default;
	virtual void Execute() override;
private:

	BurgerComponent* m_pBurgerComponent;
};

class EnemyDieCommand
	: public Command
{
public:
	EnemyDieCommand(EnemyComponent* enemyComponent)
		: m_pEnemyComponent{ enemyComponent }
	{
	}

	virtual ~EnemyDieCommand() = default;
	virtual void Execute() override;
private:

	EnemyComponent* m_pEnemyComponent;
};