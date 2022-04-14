#pragma once
#include "BaseComponent.h"
class ImgGuiRenderComponent :
    public BaseComponent
{
public:
	ImgGuiRenderComponent(dae::GameObject* pOwner);
	virtual ~ImgGuiRenderComponent() = default;
	virtual void Update() override = 0;
	virtual void Render() const = 0;
	virtual void Initialize() override = 0;
	virtual void FixedUpdate() = 0;
	virtual void RenderImgGui(bool isOpen) = 0;
private:

};

