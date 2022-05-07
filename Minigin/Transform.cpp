#include "MiniginPCH.h"
#include "Transform.h"

dae::Transform::Transform()
	: m_Position{ 0, 0, 0 }
	, m_Size{ 1, 1, 1 }
{
}

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::Transform::SetSize(const float x, const float y, const float z) {
	m_Size.x = x;
	m_Size.y = y;
	m_Size.z = z;
}
