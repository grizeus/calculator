#pragma once
#include <cstdint>
#include <utility>
#include <string>
#include "SDL_Tools.hpp"

using coordinate = std::pair<float, float>;
using u64 = uint64_t;
struct UI_Element 
{
    UI_Element();
    UI_Element(int, int, coordinate, u64, u64, u64, u64);
    int m_Height;
    int m_Width;
    coordinate m_Position;

    u64 m_BackgroundColor;
    u64 m_HoverBackgroundColor;
    u64 m_BorderColor;
    u64 m_ContentColor;

    // void Draw(std::string);
    // void Hover(bool);
private:
    SDL_Tools* m_Drawer;
};
