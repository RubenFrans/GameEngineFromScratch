#include "MiniginPCH.h"
#include "Renderer.h"
#include "SceneManager.h"
#include "Texture2D.h"
#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl.h"
#include "ImgGuiRenderComponent.h"

int GetOpenGLDriverIndex()
{
	auto openglIndex = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (auto i = 0; i < driverCount; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
			if (!strcmp(info.name, "opengl"))
				openglIndex = i;
	}
	return openglIndex;
}

void dae::Renderer::Init(SDL_Window * window)
{
	m_Window = window;
	m_Renderer = SDL_CreateRenderer(window, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}

	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL2_Init();
}

void dae::Renderer::Render() const
{
	const auto& color = GetBackgroundColor();
	SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_Renderer);

	SceneManager::GetInstance().Render();
	
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(m_Window);
	ImGui::NewFrame();
	//ImGui::ShowDemoWindow();
	RenderImgGui();
	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(m_Renderer);
}

void dae::Renderer::Destroy()
{
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	//SDL_Rect dst{};
	//dst.x = static_cast<int>(x);
	//dst.y = static_cast<int>(y);

	SDL_Rect srcRect{};

	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &srcRect.w, &srcRect.h);
	//SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &dst);

	RenderTexture(texture, x, y, srcRect);

}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y, const SDL_Rect& srcRect) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);

	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	//SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &dst);


	RenderTexture(texture, x, y, float(dst.w), float(dst.h), srcRect);

}

void dae::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y, const float width, const float height, const SDL_Rect& srcRect) const
{
	SDL_Rect dst{};
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(srcRect.w * width);
	dst.h = static_cast<int>(srcRect.h * height);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &dst);
}

void dae::Renderer::RenderImgGui() const {
	for (ImgGuiRenderComponent* comp : m_ImgGuiRenderComponents) {
		comp->RenderImgGui(true);
	}
}

void dae::Renderer::AddImgGuiRenderComponent(ImgGuiRenderComponent* imguiRenderComponent)
{
	m_ImgGuiRenderComponents.push_back(imguiRenderComponent);
}
