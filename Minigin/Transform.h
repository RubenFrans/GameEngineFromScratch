#pragma once
#include "glm/vec3.hpp"

namespace BTEngine
{
	class Transform final
	{
	public:
		Transform();
		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetSize() const { return m_Size; }
		void SetPosition(float x, float y, float z);
		void SetSize(float x, float y, float z);
	private:
		glm::vec3 m_Position;
		glm::vec3 m_Size;
	};
}
