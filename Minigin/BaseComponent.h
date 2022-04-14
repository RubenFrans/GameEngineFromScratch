#pragma once
#include "GameObject.h"
//namespace dae {
//	class GameObject;
//}

class BaseComponent
{
public:
	BaseComponent(dae::GameObject* pOwner);
	virtual ~BaseComponent() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	dae::GameObject* GetGameObject() const;
private:
	dae::GameObject* m_pOwner;

};

