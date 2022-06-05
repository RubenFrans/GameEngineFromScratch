#pragma once
#include "Singleton.h"
#include "structs.h"
class ImgGuiRenderComponent;

namespace BTEngine
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* m_Renderer{};
		SDL_Window* m_Window{};
		SDL_Color m_clearColor{};	
	public:
		void Init(SDL_Window* window);
		void Render() const;
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, const SDL_Rect& srcRect) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height, const SDL_Rect& srcRect, bool flipHorizontal, bool flipVertical) const;

		void RenderRect(const Rect& rect) const;
		void RenderCircle(const FVector2& pos, float radius);

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }

		const SDL_Color& GetBackgroundColor() const { return m_clearColor; }
		void SetBackgroundColor(const SDL_Color& color) { m_clearColor = color; }

		void AddImgGuiRenderComponent(ImgGuiRenderComponent* imguiRenderComponent);
		void RenderImgGui() const;

	private:
		std::vector<ImgGuiRenderComponent*> m_ImgGuiRenderComponents{};

	};
}

