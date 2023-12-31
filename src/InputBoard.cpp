#include "../include/InputBoard.hpp"
#include "SDL_events.h"
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
        "%","CE","C","←"
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

InputCode InputBoard::CheckInput() {
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        SDL_PollEvent(&e); 
            if (e.type == SDL_QUIT)
                return Quit;
            else if (e.type == SDL_MOUSEMOTION) {
                for (auto &button : m_Buttons) {
                    if (button.GetElement().Intersect(e.button.x, e.button.y)) {
                            if (!button.IsHover()) {
                                button.SetHover(true);
                                return Unspecify;
                            }
                    }
                    else {
                        if (button.IsHover()) {
                            button.SetHover(false);
                            return Unspecify;
                        }
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                for (auto &button : m_Buttons) {
                    if (button.GetElement().Intersect(e.button.x, e.button.y))
                        return button.GetCode();
                }
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_0:
                    return Zero;
                    break;
                case SDLK_1:
                    return One;
                    break;
                case SDLK_2:
                    return Two;
                    break;
                case SDLK_3:
                    return Three;
                    break;
                case SDLK_4:
                    return Four;
                    break;
                case SDLK_5:
                    return Five;
                    break;
                case SDLK_6:
                    return Six;
                    break;
                case SDLK_7:
                    return Seven;
                    break;
                case SDLK_8:
                    return Eight;
                    break;
                case SDLK_9:
                    return Nine;
                    break;
                case SDLK_PLUS:
                    return Plus;
                    break;
                case SDLK_MINUS:
                    return Minus;
                    break;
                case SDLK_ASTERISK:
                    return Asterisk;
                    break;
                case SDLK_SLASH:
                    return Slash;
                    break;
                case SDLK_PERCENT:
                    return Percent;
                    break;
                case SDLK_DELETE:
                    return Clear;
                    break;
                case SDLK_PERIOD:
                    return Period;
                    break;
                case SDLK_EQUALS:
                    return Equal;
                    break;
                case SDLK_BACKSPACE:
                    return Backspace;
                    break;
                default:
                    return Unspecify;
                    break;
                }
            }
        }
    return Unspecify;
}

std::array<Button, 24> InputBoard::GetButtons() const { return m_Buttons; }
