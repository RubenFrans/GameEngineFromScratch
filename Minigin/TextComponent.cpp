#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Font.h"
#include "Texture2D.h"
#include <SDL_ttf.h>
#include "Renderer.h"
#include "GameObject.h"
#include "RenderComponent.h"

TextComponent::TextComponent(dae::GameObject* pOwner)
	: BaseComponent{ pOwner }
{
}

void TextComponent::Update()
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(dae::Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		
		// texture of renderComponent
		auto texturePointer = std::make_shared<dae::Texture2D>(texture);
		GetGameObject()->GetComponent<RenderComponent>()->SetTexture(texturePointer);

		m_NeedsUpdate = false;
	}
}

void TextComponent::FixedUpdate()
{

}

TextComponent* TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
	return this;
}

TextComponent* TextComponent::SetFont(std::shared_ptr<dae::Font> font)
{
	m_Font = font;
	return this;
}
