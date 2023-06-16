#pragma once
#include <cstdint>
#include <utility>
#include <string>
#include "SDL_Tools.hpp"

struct UI_Element 
{
    int m_Height;
    int m_Width;
    std::pair<float, float> m_Position;

    uint64_t m_BackgroundColor;
    uint64_t m_HoverBackgroundColor;
    uint64_t m_BorderColor;
    uint64_t m_ContentColor;

    // void Draw(std::string);
    // void Hover(bool);
private:
    SDL_Tools* m_Drawer;
};
