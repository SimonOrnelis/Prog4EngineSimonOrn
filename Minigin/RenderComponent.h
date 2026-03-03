#pragma once
#include "BaseComponent.h"
#include <memory>

namespace dae
{
	class Texture2D;
	class RenderComponent : public dae::BaseComponent
	{
	public:
		RenderComponent(GameObject* owner);
		~RenderComponent() = default;
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Update() override;
		void Render() const override;

		void SetTexture(const std::string& filename);

	private:
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
