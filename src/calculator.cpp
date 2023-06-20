#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator()
    : m_State(new WaitOperand1())
{ }

Calculator::~Calculator()
{
}

void Calculator::SetDisplay(std::shared_ptr<Display> display)
{
    m_Display = display;
}

void Calculator::DisplayResult()
{
    
}

void Calculator::Compute()
{

}

void Calculator::UserInput(InputCode input)
{
}