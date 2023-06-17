#include "Button.hpp"

Button::Button(InputCode code)
    : m_Code(code)
{ }

void Button::Hover(bool hover)
{
    if (hover)
    {
        SDL_Renderer* renderer = GetTools()->m_Renderer;
        SDL_Rect ButtonRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()}; // TODO mb rect decrease a little for hover fill
        SDL_SetRenderDrawColor(renderer, GetHoverColor().red, GetHoverColor().green, GetHoverColor().blue, GetHoverColor().alpha);
        SDL_RenderFillRect(renderer, &ButtonRect);

        SDL_Surface* TextSurface = TTF_RenderText_Solid(GetTools()->m_Font, m_Name.c_str(), ConvertToSDLColor(GetContentColor()));
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

