#include "../include/Display.hpp"

Display::Display()
    : m_UI_Element()
{
    SetHeight(100);
    SetWidth(497);
    SetPosition(0.0f, 0.0f);
    SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    SetBorderColor( 0xCF, 0xCF, 0xCF, 0xFF);
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
}

Display::Display(ToolsPtr drawer)
    : m_UI_Element(drawer)
{
    SetHeight(100);
    SetWidth(497);
    SetPosition(0.0f, 0.0f);
    SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    SetBorderColor( 0xCF, 0xCF, 0xCF, 0xFF);
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
}

void Display::Draw(const std::string& content) {
    SDL_Renderer* renderer = GetTools()->m_Renderer;
    TTF_Font* font = GetTools()->m_Font;
    SDL_Rect DisplayRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()};
    int index;
    if (content.size() < 2)
        index = 1;
    else
        index = content.size();
    SDL_Rect AdjustR = {static_cast<int>(GetPosition().first + GetWidth() - GetWidth() * 4 / 49 * index), static_cast<int>(GetPosition().second + GetHeight() * 2 / 8 ), 0, 0}; // magics
    TTF_SizeText(font, content.c_str(), &AdjustR.w, &AdjustR.h);
    SDL_SetRenderDrawColor(renderer, GetBorderColor().red, GetBorderColor().green, GetBorderColor().blue, GetBorderColor().alpha);
    SDL_RenderDrawRect(renderer, &DisplayRect);

    SDL_Surface* TextSurface = TTF_RenderText_Solid(font, content.c_str(), m_UI_Element.ConvertToSDLColor(GetContentColor()));
    if (TextSurface == nullptr) 
        throw std::runtime_error(SDL_GetError());

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr)
        throw std::runtime_error(TTF_GetError());
    
    SDL_RenderCopy(renderer, TextTexture, nullptr, &AdjustR);
}

void Display::SetWidth(int width) { m_UI_Element.SetWidth(width); }
void Display::SetHeight(int height) { m_UI_Element.SetHeight(height); }
void Display::SetPosition(float x, float y) { m_UI_Element.SetPosition(x, y); }
void Display::SetBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBackgroundColor(r, g, b, a); }
void Display::SetContentColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetContentColor(r, g, b, a); }
void Display::SetBorderColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBorderColor(r, g, b, a); }

// uint32_t color = 0xFF;
// color = color << 8;
// color = color | 0xA5;
// color = color << 8;
// color = color | 0x12;
