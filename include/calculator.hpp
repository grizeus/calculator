#pragma once
#include <string>

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
