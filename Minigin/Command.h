#pragma once
#include "MrPepperComponent.h"

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