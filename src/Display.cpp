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
    int WidthKoeff;
    if (content.size() < 2)
        WidthKoeff = 1;
    else
        WidthKoeff = content.size();
    SDL_Rect AdjustR = {static_cast<int>(GetPosition().first + GetWidth() - GetWidth() * 4 / 49 * WidthKoeff), static_cast<int>(GetPosition().second + GetHeight() * 2 / 8 ), 0, 0}; // magics
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
