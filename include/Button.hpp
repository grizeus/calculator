#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"
// #include <string>
// TODO buttons only exists in input chanel
enum class InputCode 
{
    None = 0,
    One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Null,
    Plus, Minus, Asterisk, Slash, Percent, Inverse, Square, SquareRoot,
    Clear, ClearEntry, Coma, PlusMinus, Equals, Backspace

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
};
