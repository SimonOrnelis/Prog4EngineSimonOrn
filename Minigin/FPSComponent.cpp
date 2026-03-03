#include "FPSComponent.h"
#include "TextComponent.h"
#include <format>

dae::FPSComponent::FPSComponent(GameObject* pOwner)
	: BaseComponent(pOwner)
{
}

void dae::FPSComponent::Update(float deltaTime)
{
	if (m_Timer >= m_ResetTimer)
	{
		m_NeedsUpdate = true;
		m_Timer = 0.f;
	}
	else
	{
		m_Timer += deltaTime;
	}

	if (m_pTextComponent && m_NeedsUpdate)
	{
		m_FPS = 1.0f / deltaTime;
		std::string fpsText = std::format("FPS: {:.1f}", m_FPS);

		m_pTextComponent->SetText(fpsText);

		m_pTextComponent->Update(deltaTime);
		m_NeedsUpdate = false;
	}
}

void dae::FPSComponent::Render() const
{
}
