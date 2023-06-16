#pragma once
#include <string>
#include "Display.hpp"
#include "InputHandler.hpp"

class Calculator 
{
public:
    Calculator();
    ~Calculator();

    bool Run();
    void Compute();
    void DisplayResult();
private:
    Display m_display;
    InputHandler* m_input;
}; 
