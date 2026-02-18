#include "BaseComponent.h"

dae::BaseComponent::BaseComponent(GameObject* owner)
: m_pOwner(owner)
{
}

void dae::BaseComponent::Start()
{
}

void dae::BaseComponent::Update(float deltaTime)
{
	float _temp = 0;
	_temp += deltaTime;
}

dae::GameObject* dae::BaseComponent::GetOwner() const
{
	return m_pOwner;
}
