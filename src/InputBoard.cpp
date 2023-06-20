#include "InputBoard.hpp"
#include "Button.hpp"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include <iostream>

InputBoard::InputBoard(ToolsPtr drawer)
    : m_Drawer(drawer)
{
    const std::array<std::string, 24> Symbols = {
        "0","1","2","3","4","5","6","7","8","9",
        "+","-","X", "÷","%","⅟x","x²","√",
        "C","CE",".","±","=","⌫"
    };
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 4; ++j)
        {
            Coordinate coord = std::make_pair(static_cast<float>(30.0 + 100 * j), static_cast<float>(440.0 - 50 * i));
            AddButton(coord, Symbols[j + i * 4], static_cast<InputCode>(j + i * 4 + 1), i);
        }
}

void InputBoard::AddButton(Coordinate pos, const std::string& symbol, InputCode code, int index)
{
    m_Buttons[index] = Button(pos, m_Drawer, symbol, code);
}

InputCode InputBoard::CheckInput()
{
    // TODO GeT_SDL_Input if input Mouse_Move -> check and hover/unhover cor button
    //                    if input click -> check if click on button (or keyboardevent) -> return button code

    SDL_Event e;
    while (SDL_WaitEvent(&e))
    {
        switch (e.type)
        {
        case SDL_MOUSEMOTION:
            for (int i = 0; i < 24; ++i)
            {
                if ((e.button.x <= m_Buttons[i].GetPosition().first + m_Buttons[i].GetWidth()) &&
                  (e.button.y <= m_Buttons[i].GetPosition().second + m_Buttons[i].GetHeight()))
                    m_Buttons[i].SetHover(true);
                else
                    m_Buttons[i].SetHover(false);
            std::cout << e.button.x << " " << e.button.y << "\n"; // for debug
            }
            break;
        case SDL_MOUSEBUTTONUP:
            for (int i = 0; i < 24; ++i)
            {
                if (m_Buttons[i].GetHover())
                    return m_Buttons[i].Click();
            }
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym)
            {
            case SDLK_0:
                return Null;
            case SDLK_1:
                return One;
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
                return None;
            }
        default:
            return None;
            break;
        }
    }
    return None;
}

std::array<Button, 24> InputBoard::GetButtons() const { return m_Buttons; }