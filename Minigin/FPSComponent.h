#pragma once
#include "BaseComponent.h"

namespace dae
{
	class TextComponent;
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent(GameObject* pOwner);
		virtual ~FPSComponent() = default;

		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;

		virtual void Update(float deltaTime) override;
		virtual void Render() const override;		

		void SetTextComponent(TextComponent* textComponent) { m_pTextComponent = textComponent; }

	private:
		bool m_NeedsUpdate{ true };
		float m_ResetTimer{1.f};
		float m_Timer{};
		float m_FPS{};
		TextComponent* m_pTextComponent{nullptr};
	};
}