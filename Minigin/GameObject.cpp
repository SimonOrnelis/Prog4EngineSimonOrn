#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"
#include "TestTextComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime){
	float totalDeltaTime = deltaTime;
	totalDeltaTime += deltaTime;
	for (auto& c : m_Components)
		c->Update();

}

void dae::GameObject::Render() const
{
	for (const auto& pComp : m_Components)
	{
		pComp->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
