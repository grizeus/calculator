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
        Color& operator=(const Color& c) {this->r = c.r;this->g = c.g;this->b = c.b;this->a = c.a; return *this; }
        Color(const Color& c) { this->r = c.r;this->g = c.g;this->b = c.b;this->a = c.a; }
    };
    UI_Element(int, int, coordinate, Color, Color, Color, Color, SDL_Tools*);

    virtual void Draw(std::string) = 0;
    virtual void Hover(bool) = 0;

    inline void SetHeight(int h) { m_Height = h; }
    inline void SetWidth(int w) { m_Width = w; }
    inline void SetCoordinate (float x, float y) { m_Position = std::make_pair(x, y); }
    inline void SetBackgroundColor(Color b) { m_BackgroundColor.r = b.r; m_BackgroundColor.g = b.g; m_BackgroundColor.b = b.b; m_BackgroundColor.a = b.a; }
    inline void SetHoverColor(Color h) { m_HoverBackgroundColor = h; }
    inline void SetBorderColor(Color b) { m_BorderColor = b; }
    inline void SetContentColor(Color c) { m_ContentColor = c; }
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