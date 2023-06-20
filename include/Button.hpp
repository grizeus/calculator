#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"
// TODO buttons only exists in input chanel

enum InputCode 
{
    None = 0,
    Null, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Plus, Minus, Asterisk, Slash, Percent, Inverse, Square, SquareRoot,
    Clear, ClearEntry, Period, PlusMinus, Equal, Backspace
};

class Button : public UI_Element
{
public:
    Button() = default;
    Button(Coordinate, ToolsPtr, const std::string&, InputCode);

    ~Button();

    void Hover(bool) override;
    bool Draw(const std::string&) override;
    InputCode Click();

    void SetHover(bool);

    bool GetHover() const;
    InputCode GetCode() const;
    std::string GetSymbol() const;
private:
    std::string m_Symbol;
    InputCode m_Code;
    bool m_IsHover;
};
