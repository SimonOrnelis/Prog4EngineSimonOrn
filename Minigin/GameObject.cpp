#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "BaseComponent.h"


const glm::vec3& dae::GameObject::GetWorldPosition()
{
	if (m_IsPositionDirty)
		UpdateWorldPosition();
	return m_WorldPosition;
}

void dae::GameObject::UpdateWorldPosition()
{
	if (m_IsPositionDirty)
	{
		if (m_pParent == nullptr)
			m_WorldPosition = m_LocalPosition;
		else
			m_WorldPosition = m_pParent->GetWorldPosition() + m_LocalPosition;
	}
	m_IsPositionDirty = false;
}

void dae::GameObject::SetLocalPosition(const glm::vec3& pos)
{
	m_LocalPosition = pos;
	SetPositionDirty();
}

bool dae::GameObject::IsChild(GameObject* parent) const
{
	for (const auto& child : m_Childeren)
	{
		if (child == parent || child->IsChild(parent))
			return true;
	}
	return false;
}

void dae::GameObject::SetParent(GameObject* parent, bool keepWorldPosition)
{
	if (IsChild(parent) || parent == this || m_pParent == parent)
		return;
	if(parent == nullptr)
		SetLocalPosition(GetWorldPosition());
	else
	{
		if (keepWorldPosition)
			SetLocalPosition(GetWorldPosition() - parent->GetWorldPosition());
		SetPositionDirty();
	}
	if (m_pParent) m_pParent->RemoveChild(this);
	m_pParent = parent;
	if (m_pParent) m_pParent->AddChild(this);
}

void dae::GameObject::AddChild(GameObject* child)
{
	m_Childeren.push_back(child);
	child->SetParent(this, true);
}

void dae::GameObject::RemoveChild(GameObject* child)
{
	m_Childeren.erase(std::ranges::find(m_Childeren, child));
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime){
	float totalDeltaTime = deltaTime;
	totalDeltaTime += deltaTime;
	for (auto& c : m_Components)
		c->Update(deltaTime);
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
