#include "../include/Calculator.hpp"
#include <iostream>

namespace {
    auto IsDigit = [](InputCode input) -> bool {
        return (input == Zero || input == One || input == Two || input == Three || input == Four || input == Five || input == Six
                                                                            || input == Seven || input == Eight || input == Nine);
    };

    auto IsBinOperator = [](InputCode input) -> bool {
        return (input == Plus || input == Minus || input == Asterisk || input == Slash);
    };

    auto IsUnOperator = [](InputCode input) -> bool {
        return (input == Percent || input == Square || input == SquareRoot || input == Inverse);
    };
}

Calculator::Calculator(ToolsPtr drawer)
    : m_CurrentState(State::WaitForOperand1)
    , m_Display(drawer)
    , m_Op(0)
    , m_Operand1()
    , m_Operand2()
{ }

// void Calculator::HandleOperator() {
//     if (m_Op == 0)
//         return;
//     switch (m_Op) {
//         case '+':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
//             break;
//         case '-':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
//             break;
//         case '*':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
//             break;
//         case '/':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
//             break;
//         case '%':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand()));
//             break;
//         case 's':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand()));
//             break;
//         case 'r':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand()));
//             break;
//         case 'i':
//             m_Operand1 = std::to_string(Compute(m_Operand1.getOperand()));
//             break;
//         default:
//             break;
//     }
// }

void Calculator::DisplayResult() {
    if (m_CurrentState == State::WaitForOperand1) {
        if (m_Operand1.getOperand().empty()) {
            std::cout << "Size op1: " << m_Operand1.getOperand().size() << std::endl;
            std::cout << "0" << std::endl;
            m_Display.Draw("0");
        }
        else {
            std::cout << "Size op1: " << m_Operand1.getOperand().size() << std::endl;
            std::cout << m_Operand1.getOperand() << std::endl;
            m_Display.Draw(m_Operand1.getOperand());
        }
    }
    else {
        if (m_Operand2.getOperand().empty()) {
            std::cout << "Size op1: " << m_Operand1.getOperand().size() << std::endl;
            std::cout << "0" << std::endl;
            m_Display.Draw(m_Operand1.getOperand());
        }
        else {
            std::cout << "Size op2: " << m_Operand2.getOperand().size() << std::endl;
            std::cout << m_Operand2.getOperand() << std::endl;
            m_Display.Draw(m_Operand2.getOperand());
        }
    }
}


void Calculator::Processing(InputCode input) {
    switch (m_CurrentState) {
        case State::WaitForOperand1:
            if (IsDigit(input))
                m_Operand1 += InputCodeMap[input];
            else if (input == Period && !m_Operand1.getHasPeriodTyped()) {
                m_Operand1 += InputCodeMap[input];
                m_Operand1.setHasPeriodTyped(true);
            }
            else if (input == PlusMinus) {
                if (!m_Operand1.getIsNegative()) {
                    m_Operand1.getOperand() += "-" ;
                    m_Operand1.setIsNegative(true);
                }
                else {
                    m_Operand1.getOperand().erase(m_Operand1.getOperand().begin());
                    m_Operand1.setIsNegative(false);
                }
            }
            else if (input == ClearEntry) {
                m_Operand1.getOperand().clear();
            }
            else if (input == Clear) {
                m_Operand1.getOperand().clear();
                m_Operand2.getOperand().clear();
            }
            else if (input == Backspace) {
                if (m_Operand1.getOperand().size() < 2) {
                    m_Operand1.getOperand().clear();
                    return;
                }
                else if (m_Operand1.getOperand().back() == '.')
                    m_Operand1.setHasPeriodTyped(false);
                else if (m_Operand1.getOperand().back() == '-') {
                    if (m_Operand1.getOperand().size() == 2) {
                        m_Operand1.getOperand().clear();
                        return;
                    }
                    m_Operand1.setIsNegative(false);
                }
                m_Operand1.getOperand().pop_back();
            }
            else if (IsUnOperator(input)) {
                m_Op = InputCodeMap[input][0];
                // HandleOperator();
                m_Operand1 = std::to_string(Compute(m_Operand1.getOperand()));
                if (IsDigit(input)) {
                    m_Operand1.getOperand().clear();
                    m_CurrentState = State::WaitForOperand1;
                }   
            }
            else if (IsBinOperator(input)){
                m_Op = InputCodeMap[input][0];
                // HandleOperator();
                m_CurrentState = State::WaitForOperand2;
            }
            break;
        
        case State::WaitForOperand2:
            if (IsDigit(input))
                m_Operand2 += InputCodeMap[input];
            else if (input == Period && !m_Operand2.getHasPeriodTyped()) {
                m_Operand2 += InputCodeMap[input];
                m_Operand2.setHasPeriodTyped(true);
            }
            else if (input == PlusMinus) {
                if (!m_Operand2.getIsNegative()) {
                    m_Operand2.getOperand() += "-" ;
                    m_Operand2.setIsNegative(true);
                }
                else {
                    m_Operand2.getOperand().erase(m_Operand2.getOperand().begin());
                    m_Operand2.setIsNegative(false);
                }
            }
            else if (input == ClearEntry) {
                m_Operand2.getOperand().clear();
            }
            else if (input == Clear) {
                m_Operand1.getOperand().clear();
                m_Operand2.getOperand().clear();
            }
            else if (input == Backspace) {
                if (m_Operand2.getOperand().size() < 2) {
                    m_Operand2.getOperand().clear();
                    return;
                }
                else if (m_Operand2.getOperand().back() == '.')
                    m_Operand2.setHasPeriodTyped(false);
                else if (m_Operand2.getOperand().back() == '-') {
                    if (m_Operand2.getOperand().size() == 2) {
                        m_Operand2.getOperand().clear();
                        return;
                    }
                    m_Operand2.setIsNegative(false);
                }
                m_Operand2.getOperand().pop_back();
            }
            else if (IsUnOperator(input)) {
                m_Op = InputCodeMap[input][0];
                // HandleOperator();
                m_Operand2 = std::to_string(Compute(m_Operand2.getOperand()));
            }
            else if (IsBinOperator(input)) {
                m_Op = InputCodeMap[input][0];
                if (!m_Operand2.getOperand().empty()){
                    m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
                }
                // HandleOperator();
                m_CurrentState = State::WaitForOperand2;
            }
            else if (input == Equal) {
                if (m_Operand2.getOperand().empty()){
                    m_Operand2 = m_Operand1;
                }
                m_Operand1 = std::to_string(Compute(m_Operand1.getOperand(), m_Operand2.getOperand()));
                m_Operand2.getOperand().clear();
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
            result = std::stod(str) * std::stod(str);
        case 'r':
            result = std::sqrt(std::stod(str));
        case 'i':
            result = 1 / std::stod(str);
    }
    return result;
}
