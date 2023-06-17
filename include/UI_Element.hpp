#pragma once
#include <cstdint>
#include <utility>
#include <string>
#include "SDL_Tools.hpp"
#include <memory>

using coordinate = std::pair<float, float>;
class UI_Element 
{
public:
    class Color
    {
    public:
        Color() = default;
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
            : red(r), green(g), blue(b), alpha(a)
        { }
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
    };
    // UI_Element(int, int, coordinate, Color, Color, Color, Color, SDL_Tools*);
    UI_Element(SDL_Tools* drawer);
    virtual void Draw(std::string) = 0;
    virtual void Hover(bool) = 0;

    int GetHeight() const{ return m_Height; }
    int GetWidth() const { return m_Width; }
    coordinate GetPosition() const {return m_Position; } 
    Color GetBackgroundColor() const{ return m_BackgroundColor; }
    Color GetHoverColor() const { return m_HoverBackgroundColor; }
    Color GetBorderColor() const { return m_BorderColor; }
    Color GetContentColor() const { return m_ContentColor; }

    inline void SetHeight(int);
    inline void SetWidth(int);
    inline void SetPosition(float, float);
    inline void SetBackgroundColor(uint8_t, uint8_t, uint8_t, uint8_t);
    inline void SetHoverColor(uint8_t, uint8_t, uint8_t, uint8_t);
    inline void SetBorderColor(uint8_t, uint8_t, uint8_t, uint8_t);
    inline void SetContentColor(uint8_t, uint8_t, uint8_t, uint8_t);

private:
    int m_Height;
    int m_Width;
    coordinate m_Position;

    Color m_BackgroundColor;
    Color m_HoverBackgroundColor;
    Color m_BorderColor;
    Color m_ContentColor;
    std::shared_ptr<SDL_Tools> m_Drawer;
};
