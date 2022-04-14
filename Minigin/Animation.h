#pragma once
#include "Texture2D.h"
#include "SDL_rect.h"
class Animation
{
public:
    Animation();
    ~Animation();
    void UpdateCurrentFrame();
    void SetSpriteSheet(const std::string& filename);
    void SetSpriteSheet(std::shared_ptr<dae::Texture2D> texture);
    void SetAnimationSpeed(int framesPerSecond);
    void SetCellSize(int width, int height);
    SDL_Rect GetCurrentFrameTexture() const;
    std::shared_ptr<dae::Texture2D> m_pSpriteSheet{};
    int m_AnimationFramesPerSecond;

    int m_AmountOfColumns;
    int m_AmountOfRows;

    int m_CurrentCellColumn;
    int m_CurrentCellRow;
    int m_CellWidth;
    int m_CellHeigth;

    float m_CurrentFrameTime;
private:

};

