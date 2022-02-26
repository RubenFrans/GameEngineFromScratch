#include "MiniginPCH.h"
#include "ImGuiPlotComponent.h"
#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl.h"
#include "Renderer.h"

ImGuiPlotComponent::ImGuiPlotComponent(dae::GameObject* pOwner)
	: ImgGuiRenderComponent(pOwner)
{
    dae::Renderer::GetInstance().AddImgGuiRenderComponent(this);
}

void ImGuiPlotComponent::Update()
{

}

void ImGuiPlotComponent::RenderImgGui(bool isOpen = true) {


    ImGui::ShowDemoWindow(&isOpen);
    
    ImGui::Begin("Exercise 1");
    ImGui::InputInt("# samples", &m_NrOfSamples);
    ImGui::End();


}

void ImGuiPlotComponent::FixedUpdate()
{

}

void ImGuiPlotComponent::Render() const
{

}
