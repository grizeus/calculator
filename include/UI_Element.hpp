#pragma once
#include <cstdint>
#include <utility>
#include <string>
#include "SDL_Tools.hpp"
#include <memory>

using coordinate = std::pair<float, float>;
using Tools = std::shared_ptr<SDL_Tools>;

class UI_Element 
{
public:
    struct Color
    {
    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : red(r), green(g), blue(b), alpha(a) {}
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    };

    SDL_Color ConvertToSDLColor(const Color& c) 
    {
        SDL_Color SDLColor;
        SDLColor.r = c.red;
        SDLColor.g = c.green;
        SDLColor.b = c.blue;
        SDLColor.a = c.alpha;
        return SDLColor;
    }

    UI_Element() = default;
    UI_Element(Tools);
    virtual ~UI_Element() {}

    virtual bool Draw(const std::string&) = 0;
    virtual void Hover(bool) = 0;

    int GetHeight() const{ return m_Height; }
    int GetWidth() const { return m_Width; }
    coordinate GetPosition() const {return m_Position; } 
    Color GetBackgroundColor() const{ return m_BackgroundColor; }
    Color GetHoverColor() const { return m_HoverBackgroundColor; }
    Color GetBorderColor() const { return m_BorderColor; }
    Color GetContentColor() const { return m_ContentColor; }
    Tools GetTools() const { return m_Drawer; }

    void SetHeight(int);
    void SetWidth(int);
    void SetPosition(float, float);
    void SetBackgroundColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetHoverColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetBorderColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetContentColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetDrawer(Tools);
private:
    int m_Height;
    int m_Width;
    coordinate m_Position;

    Color m_BackgroundColor;
    Color m_HoverBackgroundColor;
    Color m_BorderColor;
    Color m_ContentColor;
    Tools m_Drawer;
};
