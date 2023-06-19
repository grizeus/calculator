#include "InputBoard.hpp"
#include "Button.hpp"
#include "UI_Element.hpp"

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
}