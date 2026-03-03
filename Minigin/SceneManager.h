#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Scene.h"
#include "Singleton.h"

namespace dae
{
	class Scene;
	class GameObject;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene();

		SceneManager();
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
		void Render();
		void DeleteMarkedObjects();

	private:
		friend class Singleton<SceneManager>;
		std::vector<std::unique_ptr<Scene>> m_scenes{};
		std::unique_ptr<GameObject> m_pPlayer{ nullptr };
	};
}
