#pragma once

#pragma warning(push, 1)
#include "glm/vec3.hpp"
#pragma warning(pop)


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

		Transform operator+(const Transform& rhs);

	private:
		glm::vec3 m_Position;
		glm::vec3 m_Size;
	};
}
