#include "InputBoard.hpp"
#include "Button.hpp"

InputBoard::InputBoard(ToolsPtr drawer)
    : m_Drawer(drawer)
{
    const std::array<std::string, 24> Symbols = {
        "0","1","2","3","4","5","6","7","8","9",
        "+","-","X", "÷","%","⅟x","x²","√",
        "C","CE",".","±","=","⌫"
    };
    for (int i = 0; i < 24; ++i)
        AddButton(Symbols[i], static_cast<InputCode>(i + 1), i);
}

void InputBoard::AddButton(const std::string& symbol, InputCode code, int index)
{
    m_Buttons[index] = Button(symbol, code, m_Drawer);
}

InputCode InputBoard::CheckInput()
{
    // TODO GeT_SDL_Input if input Mouse_Move -> check and hover/unhover cor button
    //                    if input click -> check if click on button (or keyboardevent) -> return button code
}