#pragma once
#include <string>
#include <memory>
#include <typeindex>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include "Transform.h"
#include "BaseComponent.h"
namespace dae
{
	class Texture2D;
	class BaseComponent;
	class GameObject 
	{
		Transform m_Transform{};
		std::shared_ptr<Texture2D> m_Texture{};
		std::vector<std::unique_ptr<BaseComponent>> m_Components;
		//std::unordered_map<std::type_index, std::vector<BaseComponent*>> index_;//?

	public:
		template<typename T, typename... Args>
		T& AddComponent(Args&&... args) {
			static_assert(std::is_base_of_v<BaseComponent, T>, "T must inherit BaseComponent");
			auto ptr = std::make_unique<T>(this, std::forward<Args>(args)...);
			T* raw = ptr.get();
			m_Components.push_back(std::move(ptr));
			//index_[std::type_index(typeid(T))].push_back(raw);
			//raw->Start();
			return *raw;
		}

		virtual void Update(float deltaTime);
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
	};
}
