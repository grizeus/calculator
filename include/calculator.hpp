#pragma once
#include <string>
#include "Display.hpp"
#include "InputBoard.hpp"
#include <memory>
// TODO Calculator is state machine (wait 1 operand; wait 2 operand)
class Calculator 
{
public:
    Calculator();
    ~Calculator();

    int Run();
    void Compute();
    void DisplayResult();
    void UserInput(InputCode);
private:
    std::shared_ptr<Display> Display;
};