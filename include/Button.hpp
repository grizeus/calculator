#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"
// TODO buttons only exists in input chanel

enum InputCode 
{
    None = 0,
    Null, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Plus, Minus, Asterisk, Slash, Percent, Inverse, Square, SquareRoot,
    Clear, ClearEntry, Period, PlusMinus, Equals, Backspace
};

class Button : public UI_Element
{
public:
    Button() = default;
    Button(const std::string&, InputCode, ToolsPtr);
    ~Button();

    void Hover(bool) override;
    bool Draw(const std::string&) override;
    InputCode Click();
private:
    std::string m_Symbol;
    InputCode m_Code;
    
    ToolsPtr m_Drawer;
};
