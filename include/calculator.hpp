#pragma once
#include "Button.hpp"
#include "Display.hpp"
#include "InputBoard.hpp"
#include <map>

enum class State {
    WaitForOperand1,
    WaitForOperator,
    WaitForOperand2,
};

class Calculator {

public:
    Calculator();
    ~Calculator();

    void DisplayResult();
    void SetDisplay(std::shared_ptr<Display>);
    void Processing(InputCode input);

    double Compute(const std::string&, const std::string&);
    double Compute(const std::string&);
private:
    State m_CurrentState;
    std::string m_Operand1;
    std::string m_Operand2;
    unsigned char m_Op;
    bool HasPeriodTyped = false;
    bool IsNegative = false;
    std::shared_ptr<Display> m_Display;
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