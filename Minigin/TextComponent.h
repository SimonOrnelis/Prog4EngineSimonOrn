#pragma once
#include <string>
#include <memory>
#include <Transform.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "BaseComponent.h"

namespace dae
{
	class Font;
	class Texture2D;
	class GameObject;
	class TextComponent : public BaseComponent
	{
	public:
		TextComponent(GameObject* owner);
		~TextComponent() = default;

		void Update(float) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetText(const std::string& text, std::shared_ptr<Font> font, const SDL_Color& color = { 255, 255, 255, 255 });
		void SetColor(const SDL_Color& color);

		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

		Texture2D* GetTexture() const { return m_TextTexture.get(); }
	private:
		bool m_NeedsUpdate{};
		std::string m_Text{};
		SDL_Color m_Color{ 255, 255, 255, 255 };
		std::shared_ptr<Font> m_Font{};
		std::shared_ptr<Texture2D> m_TextTexture{};
	};
}