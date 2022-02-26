#pragma once
#include "RenderComponent.h"
#include "ImgGuiRenderComponent.h"
class ImGuiPlotComponent
	: public ImgGuiRenderComponent
{
public:
	ImGuiPlotComponent(dae::GameObject* pOwner);
	virtual ~ImGuiPlotComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() const override;
	virtual void RenderImgGui(bool isOpen) override;
	void SetData();
private:
	int m_NrOfSamples;
};

