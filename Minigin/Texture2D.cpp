#include "MiniginPCH.h"
#include "Texture2D.h"

BTEngine::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

SDL_Texture* BTEngine::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

BTEngine::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}
