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

BTEngine::Transform BTEngine::Transform::operator+(const Transform& rhs) {

	Transform result{};

	glm::vec3 size = GetSize() * rhs.GetSize();
	result.SetSize(size.x, size.y, size.z);

	glm::vec3 position = GetPosition() + rhs.GetPosition();
	//result.SetPosition(position.x + (size.x / 2.f), position.y + (size.y / 2.f), position.z + (size.z / 2.f));
	result.SetPosition(position.x, position.y, position.z);

	return result;
}
