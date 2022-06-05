#pragma once
#include "GameObject.h"
//namespace BTEngine {
//	class GameObject;
//}

class BaseComponent
{
public:
	BaseComponent(BTEngine::GameObject* pOwner);
	virtual ~BaseComponent() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() const {};
	BTEngine::GameObject* GetGameObject() const;
private:
	BTEngine::GameObject* m_pOwner;

};

