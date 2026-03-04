#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::Transform::SetPosition(const glm::vec3& position) 
{ 
	m_position = position; 
}

dae::Transform dae::Transform::operator-(const Transform& other) const
{
	Transform result;
	result.SetPosition(m_position - other.m_position);
	return result;
}
