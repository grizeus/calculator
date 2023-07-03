#include "../include/Operand.hpp"

Operand::Operand() {
    operand = "";
    HasPeriodTyped = false;
    IsNegative = false;
}

// maybe delete later
Operand::Operand(const std::string& string) {
    this->operand = string;
    HasPeriodTyped = false;
    IsNegative = false;
}

Operand& Operand::operator=(const Operand& operand) {
    this->operand = operand.operand;
    HasPeriodTyped = operand.HasPeriodTyped;
    IsNegative = operand.IsNegative;
    return *this;
}

Operand& Operand::operator+=(std::string operand) {
    this->operand += operand;
    return *this;
}

Operand::~Operand()
{ }

std::string& Operand::getOperand() {
    return operand;
}

bool Operand::getHasPeriodTyped() const {
    return HasPeriodTyped;
}

bool Operand::getIsNegative() const {
    return IsNegative;
}

void Operand::setOperand(std::string operand) {
    this->operand = operand;
}

void Operand::setHasPeriodTyped(bool HasPeriodTyped) {
    this->HasPeriodTyped = HasPeriodTyped;
}

void Operand::setIsNegative(bool IsNegative) {
    this->IsNegative = IsNegative;
}
