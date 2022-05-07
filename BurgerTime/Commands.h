#pragma once

#include "Command.h"
#include "MrPepperComponent.h"
#include "BurgerComponent.h"
#include "EnemyComponent.h"

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

class PlaySoundCommand
	: public Command
{
public:
	virtual ~PlaySoundCommand() = default;
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
		: m_MrPepper{ mrPepper }
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


class MoveRightCommand
	: public Command
{
public:
	MoveRightCommand(MrPepperComponent* pepperComponent)
		: m_pMrPepperComponent{ pepperComponent }
	{
	}

	virtual ~MoveRightCommand() = default;
	virtual void Execute() override;
private:
	MrPepperComponent* m_pMrPepperComponent;

};

class MoveLeftCommand
	: public Command
{
public:
	MoveLeftCommand(MrPepperComponent* pepperComponent)
		: m_pMrPepperComponent{ pepperComponent }
	{
	}

	virtual ~MoveLeftCommand() = default;
	virtual void Execute() override;
private:
	MrPepperComponent* m_pMrPepperComponent;

};

class MoveUpCommand
	: public Command
{
public:
	MoveUpCommand(MrPepperComponent* pepperComponent)
		: m_pMrPepperComponent{ pepperComponent }
	{
	}

	virtual ~MoveUpCommand() = default;
	virtual void Execute() override;
private:
	MrPepperComponent* m_pMrPepperComponent;

};

class MoveDownCommand
	: public Command
{
public:
	MoveDownCommand(MrPepperComponent* pepperComponent)
		: m_pMrPepperComponent{ pepperComponent }
	{
	}

	virtual ~MoveDownCommand() = default;
	virtual void Execute() override;
private:
	MrPepperComponent* m_pMrPepperComponent;

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
