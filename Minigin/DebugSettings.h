#pragma once
class DebugSettings
{
public:
	static void ToggleDebugRendering();
	static bool DebugDrawingEnabled();
private:
	static bool m_DebugRenderingEnabled;
};

