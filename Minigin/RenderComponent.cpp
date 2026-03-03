#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "GameObject.h"

dae::RenderComponent::RenderComponent(GameObject* owner)
	: BaseComponent(owner)
{
}

void dae::RenderComponent::Update(float)
{
}

void dae::RenderComponent::Render() const
{
	if (m_Texture != nullptr)
	{
		const auto pos{ BaseComponent::GetOwner()->GetTransform().GetPosition() };
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void dae::RenderComponent::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}
