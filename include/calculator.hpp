#pragma once
// #include <string>
#include "Display.hpp"
#include "InputBoard.hpp"
// #include <memory>

// TODO Calculator is state machine (wait 1 operand; wait 2 operand)
struct State;

class Calculator 
{
public:
    Calculator();
    ~Calculator();

    void Compute();
    void DisplayResult();
    void UserInput(InputCode);

    void SetDisplay(std::shared_ptr<Display>);
private:
    State* m_State;
    std::shared_ptr<Display> m_Display;
};

