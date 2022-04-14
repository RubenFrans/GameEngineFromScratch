#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Animation.h"
#include <unordered_map>

class RenderComponent;

class AnimationComponent :
    public BaseComponent
{
public:
    AnimationComponent(dae::GameObject* pOwnder);
    virtual ~AnimationComponent() = default;
    
    void Update() override;
    void FixedUpdate() override;
    void Initialize() override;

    void AddAnimation(int animationKey, const Animation& animation);
    void SetPlayAnimation(int animationKey);

private:
    std::shared_ptr<dae::Texture2D> m_pSpriteSheet{};
    std::unordered_map<int, Animation> m_Animations;

    Animation* m_pCurrentAnimation;


    RenderComponent* m_pRenderComponent;

};

