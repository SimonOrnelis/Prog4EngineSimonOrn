#include "SceneManager.h"
#include "Scene.h"

dae::SceneManager::SceneManager()
{
	//m_scenes[0]->Add(m_pPlayer);
}

void dae::SceneManager::Update(float deltaTime)
{
	//size_t size = m_scenes.size();
	//++size; // Just to avoid the unused variable warning. We might need this in the future when we want to implement scene switching.
	//for(auto& scene : m_scenes)
	//{
	//	scene->Update(deltaTime);
	//}
	m_scenes[0]->Update(deltaTime);
}

void dae::SceneManager::FixedUpdate(float deltaTime)
{
	//TEMPORARY: For now, we will just call the regular update. In the future, we might want to separate the fixed update logic from the regular update logic.
	for (auto& scene : m_scenes)
	{
		scene->Update(deltaTime);
	}
}

void dae::SceneManager::Render()
{
	for (const auto& scene : m_scenes)
	{
		scene->Render();
	}
}

dae::Scene& dae::SceneManager::CreateScene()
{
	m_scenes.emplace_back(new Scene());
	return *m_scenes.back();
}
