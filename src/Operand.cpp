#include "../include/Operand.hpp"

Operand::Operand() {
    data = "";
    HasPeriodTyped = false;
    IsNegative = false;
}

Operand::Operand(const std::string& string) {
    data = string;
    HasPeriodTyped = false;
    IsNegative = false;
}

Operand& Operand::operator=(const Operand& operand) {
    data = operand.data;
    HasPeriodTyped = operand.HasPeriodTyped;
    IsNegative = operand.IsNegative;
    return *this;
}

Operand& Operand::operator+=(std::string str) {
    data += str;
    return *this;
}

Operand::~Operand()
{ }
