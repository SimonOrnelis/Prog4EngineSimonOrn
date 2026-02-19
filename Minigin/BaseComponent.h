#pragma once
#include <string>
namespace dae
{
    class GameObject;
    class BaseComponent {
    public:
        explicit BaseComponent(GameObject* owner);
        virtual ~BaseComponent() = default;

        //virtual const char* Name() const = 0;

        virtual void Update(float deltaTime);

        GameObject* GetOwner() const;

    private:
        GameObject* m_pOwner;
    };
}