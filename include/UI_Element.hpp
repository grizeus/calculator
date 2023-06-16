#pragma once
#include <cstdint>
#include <utility>
#include <string>
#include "SDL_Tools.hpp"

using coordinate = std::pair<float, float>;
// TODO seter geter
class UI_Element 
{
public:
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
    UI_Element(int, int, coordinate, Color, Color, Color, Color, SDL_Tools*);

    virtual void Draw(std::string) = 0;
    virtual void Hover(bool) = 0;
private:
    int m_Height;
    int m_Width;
    coordinate m_Position;

    Color m_BackgroundColor;
    Color m_HoverBackgroundColor;
    Color m_BorderColor;
    Color m_ContentColor;
    SDL_Tools* m_Drawer;
};
