#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Font.h"
#include "Texture2D.h"
#include <SDL_ttf.h>
#include "Renderer.h"
#include "GameObject.h"
#include "RenderComponent.h"

TextComponent::TextComponent(BTEngine::GameObject* pOwner)
	: BaseComponent{ pOwner }, m_NeedsUpdate{ false }, m_Color{ 255, 255, 255 }
{
}

void TextComponent::Update()
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { m_Color.r , m_Color.g, m_Color.b }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(BTEngine::Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		
		// texture of renderComponent
		auto texturePointer = std::make_shared<BTEngine::Texture2D>(texture);
		GetGameObject()->GetComponent<RenderComponent>()->SetTexture(texturePointer);

		m_NeedsUpdate = false;
	}
}

void TextComponent::FixedUpdate()
{

}

void TextComponent::Initialize()
{
}

TextComponent* TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
	return this;
}

TextComponent* TextComponent::SetFont(std::shared_ptr<BTEngine::Font> font)
{
	m_Font = font;
	return this;
}

void TextComponent::SetColor(const RGBColor& color)
{
	m_Color = color;
}

void TextComponent::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_Color = RGBColor(r, g, b);
}
