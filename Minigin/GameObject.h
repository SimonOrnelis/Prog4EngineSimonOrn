#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Transform.h"
#include "BaseComponent.h"
namespace dae
{
	class Texture2D;
	class BaseComponent;
	class GameObject final
	{
		Transform m_Transform{};
		std::shared_ptr<Texture2D> m_Texture{};
		std::vector<std::unique_ptr<BaseComponent>> m_Components;

	public:
		template<typename T>
		T* AddComponent(GameObject* pOwner)
		{
			auto comp = std::make_unique<T>(pOwner);
			auto ptr = comp.get();
			m_Components.push_back(std::move(comp));
			return ptr;
		}

		void Update(float deltaTime);
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		Transform GetTransform() const { return m_Transform; }

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
	};
}
