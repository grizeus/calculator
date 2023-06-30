#include "../include/Calculator.hpp"
#include "Button.hpp"
#include "UI_Element.hpp"
#include <iostream>

namespace {
    bool IsDigit(InputCode input) {
      return (input == Zero || input == One || input == Two || input == Three || input == Four || input == Five || input == Six
                                                                            || input == Seven || input == Eight || input == Nine) ? true : false;
    }

    bool IsOperator (InputCode input) {
            return (input == Plus || input == Minus || input == Asterisk || input == Slash) ? true : false;
    }
}

Calculator::Calculator(ToolsPtr drawer)
    : m_CurrentState(State::WaitForOperand1)
    , m_Display(drawer)
    , m_Op(0)
{
}
// TODO write method
void Calculator::HandleOperator() {

// case State::WaitForOperator:
//             if (input == Plus || input == Minus || input == Asterisk || input == Slash) {
//                 HasPeriodTyped = false;
//                 IsNegative = false;
//                 m_Op = InputCodeMap[input][0];
//                 m_CurrentState = State::WaitForOperand2;
//             }
//             else if (input == Clear) {
//                 m_Operand1.clear();
//                 m_CurrentState = State::WaitForOperand1;
//             }
//             else if (input == Percent || input == Square || input == SquareRoot || input == Inverse) {
//                 m_Op = InputCodeMap[input][0];
//                 m_Operand1 = std::to_string(Compute(m_Operand1));
//             }
//             break;
}

void Calculator::DisplayResult() {
    if (m_CurrentState == State::WaitForOperand1) {
        if (m_Operand1.empty())
            // std::cout << "0" << std::endl;
            m_Display.Draw("0");
        else
            // std::cout << m_Operand1 << std::endl;
            m_Display.Draw(m_Operand1);
    }
    // else if (m_CurrentState == State::WaitForOperator)
    //     // std::cout << m_Operand1 << std::endl;
    //     m_Display.Draw(m_Operand1); 
    else
        // std::cout << m_Operand2 << std::endl;
        m_Display.Draw(m_Operand2);
}


void Calculator::Processing(InputCode input) {
    switch (m_CurrentState) {
        case State::WaitForOperand1:
            if (IsDigit(input))
                m_Operand1 += InputCodeMap[input];
                // m_Operand1 = "69";
            else if (input == Period && !HasPeriodTyped) {
                m_Operand1 += InputCodeMap[input];
                HasPeriodTyped = true;
            }
            else if (input == PlusMinus) {
                if (!IsNegative) {
                    m_Operand1 = "-" + m_Operand1;
                    IsNegative = true;
                }
                else {
                    m_Operand1.erase(m_Operand1.begin());
                    IsNegative = false;
                }
            }
            else if (input == ClearEntry) {
                m_Operand1.clear();
            }
            else if (input == Clear) {
                m_Operand1.clear();
                m_Operand2.clear();
            }
            else if (input == Backspace) {
                m_Operand1.pop_back();
            }
            else if (IsOperator(input)){
                m_Op = input;
                HandleOperator();
                m_CurrentState = State::WaitForOperand2;
            }
            break;
        
        case State::WaitForOperand2:
            if (IsDigit(input))
                m_Operand2 += InputCodeMap[input];
            else if (input == Period && !HasPeriodTyped) {
                m_Operand2 += InputCodeMap[input];
                HasPeriodTyped = true;
            }
            else if (input == PlusMinus) {
                if (!IsNegative) {
                    m_Operand2 = "-" + m_Operand2;
                    IsNegative = true;
                }
                else {
                    m_Operand2.erase(m_Operand2.begin());
                    IsNegative = false;
                }
            }
            else if (input == ClearEntry) {
                m_Operand2.clear();
            }
            else if (input == Clear) {
                m_Operand1.clear();
                m_Operand2.clear();
                m_CurrentState = State::WaitForOperand1;
            }
            else if (input == Backspace) {
                m_Operand1.pop_back();
            }
            else if (input == Percent || input == Square || input == SquareRoot || input == Inverse) {
                m_Op = InputCodeMap[input][0];
                m_Operand2 = std::to_string(Compute(m_Operand2));
            }
            else if (input == Plus || input == Minus || input == Asterisk || input == Slash) {
                m_Op = InputCodeMap[input][0];
                m_Operand1 = std::to_string(Compute(m_Operand1, m_Operand2));
                HandleOperator();
                m_CurrentState = State::WaitForOperand2;
            }
            else if (input == Equal) {
                if (m_Operand2.empty()){
                    m_Operand2 = m_Operand1;
                }
                m_Operand1 = std::to_string(Compute(m_Operand1, m_Operand2));
                m_CurrentState = State::WaitForOperand2;
            }
            break;
        default:
            break;
    }
}

double Calculator::Compute(const std::string& str1, const std::string& str2) {
    double result;
    switch (m_Op) {
        case '+':
            result = std::stod(str1) + std::stod(str2);
        case '-':
            result = std::stod(str1) - std::stod(str2);
        case '*':
            result = std::stod(str1) * std::stod(str2);
        case '/':
            result = std::stod(str1) / std::stod(str2);
    }
    return result;
}

double Calculator::Compute(const std::string& str) {
    double result;
    switch (m_Op) {
        case '%':
            result = std::stod(str) / 100;
        case 's':
            result = std::stod(str) * std::stod(m_Operand1);
        case 'r':
            result = std::sqrt(std::stod(str));
        case 'i':
            result = 1 / std::stod(str);
    }
    return result;
}
