#include "../include/Display.hpp"


Display::Display(ToolsPtr drawer)
    : UI_Element(drawer) 
{
    SetHeight(100);
    SetWidth(497);
    SetPosition(0.0f, 0.0f);
    SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    SetBorderColor( 0xCF, 0xCF, 0xCF, 0xFF);
    SetHoverColor (0xCF, 0xCF, 0xCF, 0xCF);
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
}

bool Display::Draw(const std::string& content) {
    SDL_Renderer* renderer = GetTools()->m_Renderer;
    SDL_Rect DisplayRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()};
    SDL_SetRenderDrawColor(renderer, GetBorderColor().red, GetBorderColor().green, GetBorderColor().blue, GetBorderColor().alpha);
    SDL_RenderDrawRect(renderer, &DisplayRect);

    SDL_Surface* TextSurface = TTF_RenderText_Solid(GetTools()->m_Font, content.c_str(), ConvertToSDLColor(GetContentColor()));
    if (TextSurface == nullptr) {
        throw std::runtime_error(SDL_GetError());
        return false;
    }

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr) {
        throw std::runtime_error(TTF_GetError());
        return false;
    }
    
    SDL_RenderCopy(renderer, TextTexture, nullptr, &DisplayRect);
    
    SDL_RenderPresent(renderer);
    return true;
}

// uint32_t color = 0xFF;
// color = color << 8;
// color = color | 0xA5;
// color = color << 8;
// color = color | 0x12;
