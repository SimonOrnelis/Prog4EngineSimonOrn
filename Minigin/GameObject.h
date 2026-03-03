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
	public:
		template<typename T>
		T* AddComponent(GameObject* pOwner)
		{
			auto comp = std::make_unique<T>(pOwner);
			auto ptr = comp.get();
			m_Components.push_back(std::move(comp));
			return ptr;
		}

		template<typename T>
		T* GetComponent() const
		{
			for (const auto& comp : m_Components)
			{
				if (auto casted = dynamic_cast<T*>(comp.get()))
				{
					return casted;
				}
			}
			return nullptr;
		}

		template<typename T>
		void RemoveComponent()
		{
			m_Components.erase(std::remove_if(m_Components.begin(), m_Components.end(),
				[](const std::unique_ptr<BaseComponent>& comp)
				{
					return dynamic_cast<T*>(comp.get()) != nullptr;
				}), m_Components.end());
		}


		void Update(float deltaTime);
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		Transform GetTransform() const { return m_Transform; }
		bool IsMarkedForDelete() const { return m_IsMarkedForDelete; }

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform{};
		std::shared_ptr<Texture2D> m_Texture{};
		std::vector<std::unique_ptr<BaseComponent>> m_Components;
		bool m_IsMarkedForDelete{ false };
	};
}
