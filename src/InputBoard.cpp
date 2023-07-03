#include "../include/InputBoard.hpp"
#include <iostream>

InputBoard::InputBoard(ToolsPtr drawer)
    : m_Drawer(drawer) 
{
    const std::array<std::string, 24> Symbols = {
        "±","0",".","=",
        "1","2","3","+",
        "4","5","6","-",
        "7","8","9","X",
        "⅟x","x²","√","÷",
        "%","CE","C","⌫"
    };

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            Coordinate coord = std::make_pair(static_cast<float>(4.0 + 127 * j), static_cast<float>(440.0 - 65 * i));
            AddButton(coord, Symbols[j + i * 4], static_cast<InputCode>(j + i * 4 + 1), (j + i * 4));
        }
    }
}

void InputBoard::AddButton(Coordinate pos, const std::string& symbol, InputCode code, int index){
    m_Buttons[index] = Button(pos, m_Drawer, symbol, code);
}

InputCode InputBoard::CheckInput(){
    SDL_Event e;
    bool quit = false;
    while (quit == false) {
            SDL_WaitEvent(&e);
            switch (e.type) {
            case SDL_MOUSEMOTION:
                for (auto &button : m_Buttons) {
                    if ((e.button.x <= (button.GetElement().GetPosition().first + button.GetElement().GetWidth()))
                        && (e.button.x >= button.GetElement().GetPosition().first)
                        && (e.button.y <= (button.GetElement().GetPosition().second + button.GetElement().GetHeight()))
                        && (e.button.y >= button.GetElement().GetPosition().second))
                    {
                        button.SetHover(true);
                        return Unspecify;
                    }
                    // else
                        // button.SetHover(false);
                    button.Draw();
                    // SDL_Delay(5);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                for (auto &button : m_Buttons) {
                    if (button.GetHover()) {
                        // SDL_Delay(5);
                        return button.Click();
                    }
                }
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                case SDLK_0:
                    return Zero;
                case SDLK_1:
                    return One;
                    break;
                case SDLK_2:
                    return Two;
                case SDLK_3:
                    return Three;
                case SDLK_4:
                    return Four;
                case SDLK_5:
                    return Five;
                case SDLK_6:
                    return Six;
                case SDLK_7:
                    return Seven;
                case SDLK_8:
                    return Eight;
                case SDLK_9:
                    return Nine;
                case SDLK_PLUS:
                    return Plus;
                case SDLK_MINUS:
                    return Minus;
                case SDLK_ASTERISK:
                    return Asterisk;
                case SDLK_SLASH:
                    return Slash;
                case SDLK_PERCENT:
                    return Percent;
                case SDLK_DELETE:
                    return Clear;
                case SDLK_PERIOD:
                    return Period;
                case SDLK_EQUALS:
                    return Equal;
                case SDLK_BACKSPACE:
                    return Backspace;
                default:
                    return Unspecify;
                }
            case SDL_QUIT:
                quit = true;
            default:
                return Unspecify;
                break;
            }
        }
    return Unspecify;
}

std::array<Button, 24> InputBoard::GetButtons() const { return m_Buttons; }
