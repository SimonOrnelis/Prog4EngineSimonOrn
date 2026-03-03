#pragma once
#include <string>
namespace dae
{
    class GameObject;
    class BaseComponent {
    public:
        explicit BaseComponent(GameObject* pOwner);
        virtual ~BaseComponent() = default;

        //virtual const char* Name() const = 0;

        virtual void Update(float) = 0;
        virtual void Render() const = 0;

        GameObject* GetOwner() const;

    private:
        GameObject* m_pOwner;
    };
}