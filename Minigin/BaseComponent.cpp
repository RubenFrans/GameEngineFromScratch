#include "MiniginPCH.h"
#include "BaseComponent.h"

BaseComponent::BaseComponent(BTEngine::GameObject* pOwner)
    : m_pOwner{ pOwner }
{

}

BTEngine::GameObject* BaseComponent::GetGameObject() const
{
    return m_pOwner;
}
