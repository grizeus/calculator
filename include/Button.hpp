#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"
// TODO buttons only exists in input chanel

enum class InputCode 
{
    None = 0,
    Null, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Plus, Minus, Asterisk, Slash, Percent, Inverse, Square, SquareRoot,
    Clear, ClearEntry, Period, PlusMinus, Equals, Backspace
};

class Button : public UI_Element
{
public:
    Button(InputCode);
    ~Button();

    void Hover(bool) override;
    bool Draw(const std::string&) override;
    InputCode Click();
private:
    std::string m_Name;
    InputCode m_Code;
    const std::string Names[24] = {
    "1","2","3","4","5","6","7","8","9","0",
    "+","-","X", "÷","%","⅟x","x²","√",
    "C","CE",".","±","=","⌫"
    };
};
