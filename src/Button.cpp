#include "../include/Button.hpp"
#include <SDL2/SDL_ttf.h>
#include <string>

Button::Button(Coordinate pos, ToolsPtr drawer, const std::string &symbol, InputCode code)
        : m_UI_Element(drawer), m_Symbol(symbol), m_Code(code) {
    SetHeight(65);
    SetWidth(127);
    SetPosition(pos.first, pos.second);
    SetBorderColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    SetBackgroundColor(0xFF, 0xFF, 0xFF, 0xFF);
    SetHoverColor(0xB0, 0xC4, 0xDE, 0xFF); // light steel blue 
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    m_IsHover = false;
}

void Button::Draw() {
    SDL_Renderer* renderer = GetTools()->m_Renderer;
    TTF_Font* font = GetTools()->m_Font;
    if (m_IsHover)
        SDL_SetRenderDrawColor(renderer, GetHoverColor().red, GetHoverColor().green, GetHoverColor().blue, GetHoverColor().alpha);
    else
        SDL_SetRenderDrawColor(renderer, GetBackgroundColor().red, GetBackgroundColor().green, GetBackgroundColor().blue, GetBackgroundColor().alpha);

    SDL_Rect ButtonRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()}; 
    SDL_RenderFillRect(renderer, &ButtonRect);
    SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(font, m_Symbol.c_str(), m_UI_Element.ConvertToSDLColor(GetContentColor()));
    if (TextSurface == nullptr) 
        throw std::runtime_error(SDL_GetError());

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr) 
        throw std::runtime_error(TTF_GetError());
    SDL_RenderCopy(renderer, TextTexture, nullptr, &ButtonRect);
    
}
