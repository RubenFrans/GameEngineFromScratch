#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include "SDL_rect.h"
#include <memory>

class TransformComponent;

class RenderComponent :
    public BaseComponent
{
public:
    RenderComponent(BTEngine::GameObject* pOwner);
    virtual ~RenderComponent() = default;
    void Update() override;
    void FixedUpdate() override;
    void Render() const;
    void Initialize() override;
    void SetTexture(const std::string& filename);
    void SetTexture(std::shared_ptr<BTEngine::Texture2D> texture);
    void SetSourceRect(const SDL_Rect& sourceRect);
    void FlipHorizontal(bool flip);
    void FlipVertical(bool flip);
private:
    std::shared_ptr<BTEngine::Texture2D> m_pTexture{};
    bool m_FlipHorizontal;
    bool m_FlipVertical;
    SDL_Rect m_SourceRect;
    TransformComponent* m_pTransformComponent;
};

