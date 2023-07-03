#pragma once
#include "SDL_Tools.hpp"
#include "Operand.hpp"
#include "Button.hpp"
#include "Display.hpp"
#include "InputBoard.hpp"
#include <map>
#include <string>
#include <memory>

enum class State {
    WaitForOperand1,
    WaitForOperand2,
};

class Calculator {
public:
    Calculator();
    Calculator(ToolsPtr drawer);
    ~Calculator() { }

    void DisplayResult();
    void Processing(InputCode input);

    double Compute(const std::string&, const std::string&);
    double Compute(const std::string&);
private:
    State m_CurrentState;
    Operand m_Operand1;
    Operand m_Operand2;
    unsigned char m_Op;
    Display m_Display;
    std::map<InputCode, std::string> InputCodeMap = {
        {Zero, "0"},
        {One, "1"},
        {Two, "2"},
        {Three, "3"},
        {Four, "4"},
        {Five, "5"},
        {Six, "6"},
        {Seven, "7"},
        {Eight, "8"},
        {Nine, "9"},
        {Period, "."},
        {Plus, "+"},
        {Minus, "-"},
        {Asterisk, "*"},
        {Slash, "/"},
        {Percent, "%"},
        {Square, "s"},
        {SquareRoot, "r"},
        {Inverse, "i"},
        {Equal, "="},
        {Clear, "C"},
        {Backspace, "<"},
    };
};
