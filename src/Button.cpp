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
    // SetHoverColor(0xF5, 0xFF, 0xFA, 0xFF); // mint cream
    SetHoverColor(0xF5, 0x00, 0x00, 0xFF);   // red cream
    SetContentColor(0x1E, 0x90, 0xFF, 0xCF); // dodger blue
    m_IsHover = false;
}

void Button::Hover() {
    SDL_Renderer* renderer = GetTools()->m_Renderer;
    SDL_Rect ButtonRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()}; 
    SDL_SetRenderDrawColor(renderer, GetHoverColor().red, GetHoverColor().green, GetHoverColor().blue, GetHoverColor().alpha);
    SDL_RenderFillRect(renderer, &ButtonRect);
    // SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(GetTools()->m_Font, m_Symbol.c_str(), ConvertToSDLColor(GetContentColor()));
    // SDL_Surface* TextSurface = TTF_RenderUNICODE_Solid(GetTools()->m_Font, 10, ConvertToSDLColor(GetContentColor())); 
    SDL_Surface* TextSurface = TTF_RenderText_Solid(GetTools()->m_Font, m_Symbol.c_str(), m_UI_Element.ConvertToSDLColor(GetContentColor()));
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
    SDL_Renderer* renderer = GetTools()->m_Renderer; 
    SDL_Rect ButtonRect = {static_cast<int>(GetPosition().first), static_cast<int>(GetPosition().second), GetWidth(), GetHeight()}; 
    SDL_SetRenderDrawColor(renderer, GetBackgroundColor().red, GetBackgroundColor().green, GetBackgroundColor().blue, GetBackgroundColor().alpha);
    SDL_RenderFillRect(renderer, &ButtonRect);
    SDL_Surface* TextSurface = TTF_RenderUTF8_Solid(GetTools()->m_Font, m_Symbol.c_str(), m_UI_Element.ConvertToSDLColor(GetContentColor()));
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
            if ((e.button.x <=GetPosition().first + GetWidth()) && (e.button.y <= GetPosition().second + GetHeight()))
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
UI_Element Button::GetElement() const { return m_UI_Element; }

void Button::SetHeight(int height) { m_UI_Element.SetHeight(height); }
void Button::SetWidth(int width) { m_UI_Element.SetWidth(width); }
void Button::SetPosition(float x, float y) { m_UI_Element.SetPosition(x, y); }
void Button::SetBorderColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBorderColor(r, g, b, a); }
void Button::SetBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBackgroundColor(r, g, b, a); }
void Button::SetHoverColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetHoverColor(r, g, b, a); }
void Button::SetContentColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetContentColor(r, g, b, a); }
void Button::SetTools(ToolsPtr tools) { m_UI_Element.SetTools(tools); }
