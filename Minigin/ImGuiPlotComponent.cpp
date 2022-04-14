#include "MiniginPCH.h"
#include "ImGuiPlotComponent.h"
#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl.h"
#include "Renderer.h"
#include "imgui_plot.h"

ImGuiPlotComponent::ImGuiPlotComponent(dae::GameObject* pOwner)
	: ImgGuiRenderComponent(pOwner), m_NrOfSamplesInt{ 10 }
{
    dae::Renderer::GetInstance().AddImgGuiRenderComponent(this);
}

ImGuiPlotComponent::~ImGuiPlotComponent()
{
    delete cacheData.xData;
    delete cacheData.yData;
    
    delete cacheDataEx2.xData;
    delete cacheDataEx2.yData;
}

void ImGuiPlotComponent::Update()
{

}

void ImGuiPlotComponent::RenderImgGui(bool) {


    //ImGui::ShowDemoWindow(&isOpen);
    ImGui::Begin("Exercise 1");
    ImGui::InputInt("# samples", &m_NrOfSamplesInt);
    if (ImGui::Button("Trash the cache")) {
        GenerateIntMetricData();
    }

    ImGui::PlotConfig conf;
    conf.values.xs = m_XDataEx1; 
    conf.values.ys = m_YDataEx1;
    conf.values.count = int(m_BufferSize);
    conf.scale.min = -1;
    conf.scale.max = 15000;
    conf.tooltip.show = false;
    conf.tooltip.format = "x=%.2f, y=%.2f";
    conf.grid_x.show = true;
    conf.grid_y.show = true;
    conf.frame_size = ImVec2(200, 100);
    conf.line_thickness = 2.f;
    conf.values.color = ImColor(1.0, .5f, 0.f);

    ImGui::Plot("Plot1", conf);
    ImGui::End();


    ImGui::Begin("Exercise 2");
    ImGui::InputInt("# samples", &m_NrOfSamplesClass);
    if (ImGui::Button("Trash the cache 3d transform")) {
        GenerateClassMetricData();
    }

    ImGui::PlotConfig conf2;
    conf2.values.xs = m_XDataEx2;
    conf2.values.ys = m_YDataEx2;
    conf2.values.count = int(m_BufferSize);
    conf2.scale.min = -1;
    conf2.scale.max = 3000;
    conf2.tooltip.show = false;
    conf2.tooltip.format = "x=%.2f, y=%.2f";
    conf2.grid_x.show = true;
    conf2.grid_y.show = true;
    conf2.frame_size = ImVec2(200, 100);
    conf2.line_thickness = 2.f;
    conf2.values.color = ImColor(1.0, .5f, 0.f);

    ImGui::Plot("Plot2", conf2);
    ImGui::End();
}

void ImGuiPlotComponent::GenerateIntMetricData()
{

    cacheData = cacheGen::CacheDataGenerator::GenerateIntCacheMetrics(m_NrOfSamplesInt);
    m_XDataEx1 = &cacheData.xData->at(0);
    m_YDataEx1 = &cacheData.yData->at(0);
    m_BufferSize = cacheData.yData->size();
}

void ImGuiPlotComponent::GenerateClassMetricData()
{
    delete cacheDataEx2.xData;
    delete cacheDataEx2.yData;

    cacheDataEx2 = cacheGen::CacheDataGenerator::GenerateClassCacheMetrics(m_NrOfSamplesInt);
    m_XDataEx2 = &cacheDataEx2.xData->at(0);
    m_YDataEx2 = &cacheDataEx2.yData->at(0);
    m_BufferSize = cacheDataEx2.yData->size();
}

void ImGuiPlotComponent::FixedUpdate()
{

}

void ImGuiPlotComponent::Initialize()
{
}

void ImGuiPlotComponent::Render() const
{

}
