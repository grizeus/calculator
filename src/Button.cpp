#include "../include/Button.hpp"
#include <SDL2/SDL_ttf.h>
#include <string>

Button::Button(Coordinate pos, ToolsPtr drawer, const std::string& symbol, InputCode code)
    : m_Symbol(symbol), m_Code(code)
{
    std::shared_ptr<UI_Element> m_UI_Element(new UI_Element(drawer));
    m_UI_Element->SetHeight(65);
    m_UI_Element->SetWidth(127);
    m_UI_Element->SetPosition(pos.first, pos.second);
    m_UI_Element->SetBorderColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    m_UI_Element->SetBackgroundColor(0xFF, 0xFF, 0xFF, 0xFF);
    // SetHoverColor(0xF5, 0xFF, 0xFA, 0xFF); // mint cream
    m_UI_Element->SetHoverColor(0xF5, 0x00, 0x00, 0xFF); // red cream
    m_UI_Element->SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    m_IsHover = false;
}

void Button::Hover() {
    SDL_Renderer* renderer = m_UI_Element->GetTools()->m_Renderer;
    SDL_Rect ButtonRect = {static_cast<int>(m_UI_Element->GetPosition().first), static_cast<int>(m_UI_Element->GetPosition().second), m_UI_Element->GetWidth(), m_UI_Element->GetHeight()}; 
    SDL_SetRenderDrawColor(renderer, m_UI_Element->GetHoverColor().red, m_UI_Element->GetHoverColor().green, m_UI_Element->GetHoverColor().blue, m_UI_Element->GetHoverColor().alpha);
    SDL_RenderFillRect(renderer, &ButtonRect);
    // SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(GetTools()->m_Font, m_Symbol.c_str(), ConvertToSDLColor(GetContentColor()));
    // SDL_Surface* TextSurface = TTF_RenderUNICODE_Solid(GetTools()->m_Font, 10, ConvertToSDLColor(GetContentColor())); 
    SDL_Surface* TextSurface = TTF_RenderText_Solid(m_UI_Element->GetTools()->m_Font, m_Symbol.c_str(), m_UI_Element->ConvertToSDLColor(m_UI_Element->GetContentColor()));
    if (TextSurface == nullptr)
        throw std::runtime_error(SDL_GetError());

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr)
        throw std::runtime_error(TTF_GetError());
    SDL_RenderCopy(renderer, TextTexture, nullptr, &ButtonRect);

    SDL_RenderPresent(renderer);
}

void Button::Draw() {
    SDL_Renderer* renderer = m_UI_Element->GetTools()->m_Renderer; 
    SDL_Rect ButtonRect = {static_cast<int>(m_UI_Element->GetPosition().first), static_cast<int>(m_UI_Element->GetPosition().second), m_UI_Element->GetWidth(), m_UI_Element->GetHeight()}; 
    SDL_SetRenderDrawColor(renderer, m_UI_Element->GetBackgroundColor().red, m_UI_Element->GetBackgroundColor().green, m_UI_Element->GetBackgroundColor().blue, m_UI_Element->GetBackgroundColor().alpha);
    SDL_RenderFillRect(renderer, &ButtonRect);
    SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(m_UI_Element->GetTools()->m_Font, m_Symbol.c_str(), m_UI_Element->ConvertToSDLColor(m_UI_Element->GetContentColor()));
    if (TextSurface == nullptr) 
        throw std::runtime_error(SDL_GetError());

    SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_FreeSurface(TextSurface);
    if (TextTexture == nullptr) 
        throw std::runtime_error(TTF_GetError());
    SDL_RenderCopy(renderer, TextTexture, nullptr, &ButtonRect);
    
    SDL_RenderPresent(renderer);
}

void Button::FinalDraw() {
    if (m_IsHover)
        Hover();
    else
        Draw();
}

InputCode Button::Click() {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        switch (e.type) {
        case SDL_MOUSEBUTTONUP:
            if ((e.button.x <=m_UI_Element->GetPosition().first + m_UI_Element->GetWidth()) && (e.button.y <= m_UI_Element->GetPosition().second + m_UI_Element->GetHeight()))
                return m_Code;
            break;
        default:
            return None;
        }
    }
    return None;
}

void Button::SetHover(bool hover) { m_IsHover = hover; }

bool Button::GetHover() const { return m_IsHover; }

InputCode Button::GetCode() const { return m_Code; }

std::string Button::GetSymbol() const { return m_Symbol; }

std::shared_ptr<UI_Element> Button::GetElement() const { return m_UI_Element; }
