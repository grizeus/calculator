#include "../include/Calculator.hpp"
#include <iostream>

Calculator::Calculator()
    : m_CurrentState(State::WaitForOperand1)
{ }

void Calculator::SetDisplay(std::shared_ptr<Display> display) {
    m_Display = display;
}

void Calculator::DisplayResult() {
    m_Display->Draw("RESULT");
}

void Calculator::Processing(InputCode input) {
    switch (m_CurrentState) {
        case State::WaitForOperand1:
            if (input == Zero || input == One || input == Two || input == Three || input == Four || input == Five || input == Six
                                                                            || input == Seven || input == Eight || input == Nine) {
                m_Operand1 += InputCodeMap[input];
            }
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
            else
                m_CurrentState = State::WaitForOperator;
            break;
        case State::WaitForOperator:
            if (input == Plus || input == Minus || input == Asterisk || input == Slash) {
                HasPeriodTyped = false;
                IsNegative = false;
                m_Op = InputCodeMap[input][0];
                m_CurrentState = State::WaitForOperand2;
            }
            else if (input == Clear) {
                m_Operand1.clear();
                m_CurrentState = State::WaitForOperand1;
            }
            else if (input == Percent || input == Square || input == SquareRoot || input == Inverse) {
                m_Op = InputCodeMap[input][0];
                m_Operand1 = std::to_string(Compute(m_Operand1));
            }
            break;
        case State::WaitForOperand2:
            if (input == Zero || input == One || input == Two || input == Three || input == Four || input == Five || input == Six
                                                                            || input == Seven || input == Eight || input == Nine) {
                m_Operand2 += InputCodeMap[input];
            }
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
                m_Operand1 = std::to_string(Compute(m_Operand1, m_Operand2));
                m_Op = InputCodeMap[input][0];
                m_CurrentState = State::WaitForOperand2;
            }
            else if (input == Equal) {
                m_Operand1 = std::to_string(Compute(m_Operand1, m_Operand2));
                m_CurrentState = State::WaitForOperator;
            }
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
            result = sqrt(std::stod(str));
        case 'i':
            result = 1 / std::stod(str);
    }
    return result;
}