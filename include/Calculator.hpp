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
    
    inline void SetOperator(unsigned char op) { m_Op = op; }
    inline void SetOperand1(const std::string& str) { m_Operand1.data = str; }
    inline void SetOperand2(const std::string& str) { m_Operand2.data = str; }
    inline void SetNegative1(bool flag) { m_Operand1.IsNegative = flag; }
    inline void SetNegative2(bool flag) { m_Operand2.IsNegative = flag; }
    inline void SetState(State state) { m_CurrentState = state; }
    inline std::string GetOperand1() const { return m_Operand1.data; }
    inline std::string GetOperand2() const { return m_Operand2.data; }

    void DisplayResult();
    void Processing(InputCode input);

    std::string Compute(const std::string&, const std::string&);
    std::string Compute(const std::string&);
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
