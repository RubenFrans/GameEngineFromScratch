#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include "SDL_rect.h"
class RenderComponent :
    public BaseComponent
{
public:
    RenderComponent(dae::GameObject* pOwner);
    virtual ~RenderComponent() = default;
    void Update() override;
    void FixedUpdate() override;
    void Render() const;
    void Initialize() override;
    void SetTexture(const std::string& filename);
    void SetTexture(std::shared_ptr<dae::Texture2D> texture);
    void SetSourceRect(const SDL_Rect& sourceRect);
    void FlipHorizontal(bool flip);
    void FlipVertical(bool flip);
private:
    std::shared_ptr<dae::Texture2D> m_pTexture{};
    bool m_FlipHorizontal;
    bool m_FlipVertical;
    SDL_Rect m_SourceRect;
};

