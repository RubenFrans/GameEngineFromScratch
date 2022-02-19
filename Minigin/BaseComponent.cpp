#include "MiniginPCH.h"
#include "BaseComponent.h"

BaseComponent::BaseComponent(dae::GameObject* pOwner)
    : m_pOwner{ pOwner }
{

}

dae::GameObject* BaseComponent::GetGameObject() const
{
    return m_pOwner;
}
