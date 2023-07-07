#include "../include/Calculator.hpp"
#include <iomanip>
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

Calculator::Calculator()
    : m_CurrentState(State::WaitForOperand1)
    , m_Display()
    , m_Op(0)
    , m_Operand1()
    , m_Operand2()
{ }

void Calculator::DisplayResult() {
    if (m_CurrentState == State::WaitForOperand1) {
        if (m_Operand1.data.empty()) {
            std::cout << "Size op1: " << m_Operand1.data.size() << std::endl;
            std::cout << "0" << std::endl;
            m_Display.Draw("0");
        } else {
            std::cout << "Size op1: " << m_Operand1.data.size() << std::endl;
            std::cout << m_Operand1.data << std::endl;
            m_Display.Draw(m_Operand1.data);
        }
    } else {
        if (m_Operand2.data.empty()) {
            std::cout << "Size op1: " << m_Operand1.data.size() << std::endl;
            std::cout << "0" << std::endl;
            if (IsSecondTyped)
                m_Display.Draw("0");
            else
                m_Display.Draw(m_Operand1.data);
        } else {
            std::cout << "Size op2: " << m_Operand2.data.size() << std::endl;
            std::cout << m_Operand2.data << std::endl;
            m_Display.Draw(m_Operand2.data);
        }
    }
}


void Calculator::Processing(InputCode input) {
    switch (m_CurrentState) {
        case State::WaitForOperand1:
            if (IsDigit(input)) {
                if (m_Operand1.data.size() < 12)
                    m_Operand1 += InputCodeMap[input];
            }
            else if (input == Period && !m_Operand1.HasPeriodTyped) {
                m_Operand1 += InputCodeMap[input];
                m_Operand1.HasPeriodTyped = true;
            }
            else if (input == PlusMinus) {
                if (!m_Operand1.IsNegative) {
                    m_Operand1.data = "-" + m_Operand1.data;
                    m_Operand1.IsNegative= true;
                } else {
                    m_Operand1.data.erase(m_Operand1.data.begin());
                    m_Operand1.IsNegative = false;
                }
            }
            else if (input == ClearEntry) {
                m_Operand1.data.clear();
            }
            else if (input == Clear) {
                m_Operand1.data.clear();
                m_Operand2.data.clear();
            }
            else if (input == Backspace) {
                if (m_Operand1.data.size() < 2) {
                    m_Operand1.data.clear();
                    break;
                }
                else if (m_Operand1.data.back() == '.')
                    m_Operand1.HasPeriodTyped = false;
                else if (m_Operand1.data.back() == '-') {
                    if (m_Operand1.data.size() == 2) {
                        m_Operand1.data.clear();
                        break;
                    }
                    m_Operand1.IsNegative = false;
                }
                m_Operand1.data.pop_back();
            }
            else if (IsUnOperator(input)) {
                m_Op = InputCodeMap[input][0];
                m_Operand1 = Compute(m_Operand1.data);
                if (IsDigit(input)) {
                    m_Operand1.data.clear();
                    m_CurrentState = State::WaitForOperand1;
                }   
            }
            else if (IsBinOperator(input)) {
                m_Op = InputCodeMap[input][0];
                m_CurrentState = State::WaitForOperand2;
            }
            break;
        
        case State::WaitForOperand2:
            if (IsDigit(input)) {
                if (m_Operand2.data.size() < 12) {
                    m_Operand2 += InputCodeMap[input];
                    IsSecondTyped = true;
                }
            }
            else if (input == Period && !m_Operand2.HasPeriodTyped) {
                m_Operand2 += InputCodeMap[input];
                m_Operand2.HasPeriodTyped = true;
                IsSecondTyped = true;
            }
            else if (input == PlusMinus) {
                if (m_Operand2.data.empty()) {
                    if (!m_Operand1.IsNegative) {
                        m_Operand1.data = "-" + m_Operand1.data;
                        m_Operand1.IsNegative = true;
                    } else {
                        m_Operand1.data.erase(m_Operand1.data.begin());
                        m_Operand1.IsNegative = false;
                    }
                }
                else if (!m_Operand2.IsNegative) {
                    m_Operand2.data = "-" + m_Operand2.data;
                    m_Operand2.IsNegative = true;
                } else {
                    m_Operand2.data.erase(m_Operand2.data.begin());
                    m_Operand2.IsNegative = false;
                }
            }
            else if (input == ClearEntry) {
                m_Operand2.data.clear();
            }
            else if (input == Clear) {
                m_Operand1.data.clear();
                m_Operand2.data.clear();
                IsSecondTyped = false;
                m_CurrentState = State::WaitForOperand1;
            }
            else if (input == Backspace) {
                if (m_Operand2.data.size() < 2) {
                    m_Operand2.data.clear();
                    break;
                }
                else if (m_Operand2.data.back() == '.')
                    m_Operand2.HasPeriodTyped = false;
                else if (m_Operand2.data.back() == '-') {
                    if (m_Operand2.data.size() == 2) {
                        m_Operand2.data.clear();
                        break;
                    }
                    m_Operand2.IsNegative = false;
                }
                m_Operand2.data.pop_back();
            }
            else if (IsUnOperator(input)) {
                m_Op = InputCodeMap[input][0];
                if (m_Operand2.data.empty()) {
                    m_Operand1 = Compute(m_Operand1.data);
                    break;
                }
                m_Operand2 = Compute(m_Operand2.data);
            }
            else if (IsBinOperator(input)) {
                if (m_Operand2.data.empty()){
                    m_Op = InputCodeMap[input][0];
                    break;
                }
                m_Operand1 = Compute(m_Operand1.data, m_Operand2.data);
                m_Op = InputCodeMap[input][0];
                m_Operand2.data.clear();
                IsSecondTyped = false;
                m_CurrentState = State::WaitForOperand2;
            }
            else if (input == Equal) {
                if (m_Operand2.data.empty()){
                    m_Operand2 = m_Operand1;
                }
                m_Operand1 = Compute(m_Operand1.data, m_Operand2.data);
                m_Operand2.data.clear();
                IsSecondTyped = false;
                m_CurrentState = State::WaitForOperand2;
            }
            break;
        default:
            break;
    }
}

std::string Calculator::Compute(const std::string& str1, const std::string& str2) {
    double result;
    switch (m_Op) {
        case '+':
            result = std::stod(str1) + std::stod(str2);
            break;
        case '-':
            result = std::stod(str1) - std::stod(str2);
            break;
        case '*':
            result = std::stod(str1) * std::stod(str2);
            break;
        case '/':
            result = std::stod(str1) / std::stod(str2);
            break;
    }
    std::ostringstream oss;
    oss << std::setprecision(8) << std::noshowpoint << result;
    return oss.str();
}

std::string Calculator::Compute(const std::string& str) {
    double result;
    switch (m_Op) {
        case '%':
            result = std::stod(str) / 100;
            break;
        case 's':
            result = std::stod(str) * std::stod(str);
            break;
        case 'r':
            result = std::sqrt(std::stod(str));
            break;
        case 'i':
            result = 1 / std::stod(str);
            break;
    }
    std::ostringstream oss;
    oss << std::setprecision(8) << std::noshowpoint << result;
    return oss.str();
}
