#pragma once
#include <string>

struct Operand {
    Operand();
    Operand(const std::string&);
    Operand& operator=(const Operand&);
    Operand& operator+=(std::string);
    ~Operand();

    std::string data;
    bool HasPeriodTyped = false;
    bool IsNegative = false;
};
