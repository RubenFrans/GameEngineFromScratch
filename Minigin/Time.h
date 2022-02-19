#pragma once
#include "Minigin.h"

/* Time Class
* Provides easy access to different game times.
* Implemented as static class opposed to delta parameter in update function to prohibit
* passing it as a parameter and triggering a level 4 warning when set parameter is not used.
*/
class Time final
{
public:
	friend void dae::Minigin::Run(); 

	static float GetDeltaTime();
	static float GetTotalTime();
	static int GetMsPerFrame();
	static int GetMsPerFixedFrame();

private:
	static void SetDeltaTime(float deltaTime);
	static void SetTotalTime(float totalTime);

	static float m_DeltaTime;
	static float m_TotalTime;
	static const int m_MsPerFrame{ 16 }; //16 for 60 fps, 33 for 30 fps
	static const int m_MsPerFixedFrame{ 50 }; // Fixed update will run at 20FPS
};

