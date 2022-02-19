#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"

class RenderComponent :
    public BaseComponent
{
public:
    RenderComponent(dae::GameObject* pOwner);
    virtual ~RenderComponent() = default;
    void Update() override;
    void FixedUpdate() override;
    void Render() const;
    void SetTexture(const std::string& filename);
    void SetTexture(std::shared_ptr<dae::Texture2D> texture);
private:
    std::shared_ptr<dae::Texture2D> m_pTexture{};
};

