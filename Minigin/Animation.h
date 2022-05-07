#pragma once
#include "Texture2D.h"
#include "SDL_rect.h"
#include "structs.h"


class Animation
{
public:
    Animation();
    Animation(const IVector2& anchorPoint);
    ~Animation();
    void UpdateCurrentFrame();
    void SetSpriteSheet(const std::string& filename);
    void SetSpriteSheet(std::shared_ptr<dae::Texture2D> texture);
    void SetAnimationSpeed(int framesPerSecond);
    void SetCellSize(int width, int height);
    SDL_Rect GetCurrentFrameTexture() const;
    std::shared_ptr<dae::Texture2D> m_pSpriteSheet{};
    int m_AnimationFramesPerSecond;

    IVector2 m_AnchorPoint;

    int m_AmountOfColumns;
    int m_AmountOfRows;

    int m_CurrentCellColumn;
    int m_CurrentCellRow;
    int m_CellWidth;
    int m_CellHeigth;

    float m_CurrentFrameTime;

    bool m_FlipHorizontal;
    bool m_FlipVertical;
private:

};

