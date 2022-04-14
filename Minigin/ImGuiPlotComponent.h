#pragma once
#include "RenderComponent.h"
#include "ImgGuiRenderComponent.h"
#include "CacheDataGenerator.h"
class ImGuiPlotComponent
	: public ImgGuiRenderComponent
{
public:
	ImGuiPlotComponent(dae::GameObject* pOwner);
	virtual ~ImGuiPlotComponent();
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	virtual void Render() const override;
	virtual void RenderImgGui(bool isOpen) override;
	void GenerateIntMetricData();
	void GenerateClassMetricData();
private:
	int m_NrOfSamplesInt;
	int m_NrOfSamplesClass;
	const size_t buf_size = 512;
	float x_data[512];
	float y_data1[512];
	float y_data2[512];
	float y_data3[512];

	size_t m_BufferSize;
	float* m_XDataEx1;
	float* m_YDataEx1;
	float* m_XDataEx2;
	float* m_YDataEx2;
	cacheGen::CacheData cacheData;
	cacheGen::CacheData cacheDataEx2;

};

