#include "MiniginPCH.h"
#include "Transform.h"

BTEngine::Transform::Transform()
	: m_Position{ 0, 0, 0 }
	, m_Size{ 1, 1, 1 }
{
}

void BTEngine::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void BTEngine::Transform::SetSize(const float x, const float y, const float z) {
	m_Size.x = x;
	m_Size.y = y;
	m_Size.z = z;
}
