#include "Button.hpp"
#include "SDL_ttf.h"

Button::Button(Coordinate pos, ToolsPtr drawer, const std::string& symbol, InputCode code)
    : UI_Element(pos, drawer), m_Symbol(symbol), m_Code(code)
{
    SetHeight(50);
    SetWidth(100);
    SetBorderColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    SetBackgroundColor(0xFF, 0xFF, 0xFF, 0xFF);
    SetHoverColor(0xF5, 0xFF, 0xFA, 0xFF); // mint cream
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
}

void Button::Hover(bool hover)
{
    if (hover)
    {
        SDL_Renderer* renderer = GetTools()->m_Renderer;
        SDL_Rect ButtonRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()}; 
        SDL_SetRenderDrawColor(renderer, GetHoverColor().red, GetHoverColor().green, GetHoverColor().blue, GetHoverColor().alpha);
        SDL_RenderFillRect(renderer, &ButtonRect);
        SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(GetTools()->m_Font, m_Symbol.c_str(), ConvertToSDLColor(GetContentColor()));
        // SDL_Surface* TextSurface = TTF_RenderUNICODE_Solid(GetTools()->m_Font, 10, ConvertToSDLColor(GetContentColor())); 
        // SDL_Surface* TextSurface = TTF_RenderText_Solid(GetTools()->m_Font, m_Name.c_str(), ConvertToSDLColor(GetContentColor()));
        if (TextSurface == nullptr)
            throw std::runtime_error(SDL_GetError());

        SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
        SDL_FreeSurface(TextSurface);
        if (TextTexture == nullptr)
            throw std::runtime_error(TTF_GetError());
        SDL_RenderCopy(renderer, TextTexture, nullptr, &ButtonRect);
        
        SDL_RenderPresent(renderer);
    }
}