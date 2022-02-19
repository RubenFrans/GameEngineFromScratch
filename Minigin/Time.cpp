#include "MiniginPCH.h"
#include "Time.h"

float Time::m_DeltaTime{};
float Time::m_TotalTime{};

float Time::GetDeltaTime()
{
	return m_DeltaTime;
}

float Time::GetTotalTime()
{
	return m_TotalTime;
}

int Time::GetMsPerFrame()
{
	return m_MsPerFrame;
}

int Time::GetMsPerFixedFrame()
{
	return m_MsPerFixedFrame;
}

void Time::SetDeltaTime(float deltaTime)
{
	m_DeltaTime = deltaTime;
}

void Time::SetTotalTime(float totalTime)
{
	m_TotalTime = totalTime;
}
