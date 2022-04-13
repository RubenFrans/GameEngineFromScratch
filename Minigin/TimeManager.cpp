#include "MiniginPCH.h"
#include "TimeManager.h"

float TimeManager::m_DeltaTime{};
float TimeManager::m_TotalTime{};

float TimeManager::GetDeltaTime()
{
	return m_DeltaTime;
}

float TimeManager::GetTotalTime()
{
	return m_TotalTime;
}

int TimeManager::GetMsPerFrame()
{
	return m_MsPerFrame;
}

int TimeManager::GetMsPerFixedFrame()
{
	return m_MsPerFixedFrame;
}

void TimeManager::SetDeltaTime(float deltaTime)
{
	m_DeltaTime = deltaTime;
}

void TimeManager::SetTotalTime(float totalTime)
{
	m_TotalTime = totalTime;
}
