#include "../include/Display.hpp"


Display::Display(ToolsPtr drawer)
{
    std::shared_ptr<UI_Element> m_UI_Element(new UI_Element(drawer));
    m_UI_Element->SetHeight(100);
    m_UI_Element->SetWidth(497);
    m_UI_Element->SetPosition(0.0f, 0.0f);
    m_UI_Element->SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    m_UI_Element->SetBorderColor( 0xCF, 0xCF, 0xCF, 0xFF);
    m_UI_Element->SetHoverColor (0xCF, 0xCF, 0xCF, 0xCF);
    m_UI_Element->SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
}

void Display::Draw(const std::string& content) {
    SDL_Renderer* renderer = m_UI_Element->GetTools()->m_Renderer;
    SDL_Rect DisplayRect = {static_cast<int>(m_UI_Element->GetPosition().first), static_cast<int>(m_UI_Element->GetPosition().second), m_UI_Element->GetWidth(), m_UI_Element->GetHeight()};
    SDL_SetRenderDrawColor(renderer, m_UI_Element->GetBorderColor().red, m_UI_Element->GetBorderColor().green, m_UI_Element->GetBorderColor().blue, m_UI_Element->GetBorderColor().alpha);
    SDL_RenderDrawRect(renderer, &DisplayRect);

    SDL_Surface* TextSurface = TTF_RenderText_Solid(m_UI_Element->GetTools()->m_Font, content.c_str(), m_UI_Element->ConvertToSDLColor(m_UI_Element->GetContentColor()));
    if (TextSurface == nullptr) 
        throw std::runtime_error(SDL_GetError());

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr)
        throw std::runtime_error(TTF_GetError());
    
    SDL_RenderCopy(renderer, TextTexture, nullptr, &DisplayRect);
    
    SDL_RenderPresent(renderer);
}

// uint32_t color = 0xFF;
// color = color << 8;
// color = color | 0xA5;
// color = color << 8;
// color = color | 0x12;
