#include "MiniginPCH.h"
#include "DebugSettings.h"

bool DebugSettings::m_DebugRenderingEnabled{ false };

void DebugSettings::ToggleDebugRendering()
{
	m_DebugRenderingEnabled = !m_DebugRenderingEnabled;
}

bool DebugSettings::DebugDrawingEnabled() {
	return m_DebugRenderingEnabled;
}
