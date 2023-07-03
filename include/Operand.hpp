#pragma once
#include <string>

class Operand {
public:
    Operand();
    Operand(const std::string&);
    Operand& operator=(const Operand&);
    Operand& operator+=(std::string);
    ~Operand();

    std::string& getOperand();
    bool getHasPeriodTyped() const;
    bool getIsNegative() const;

    void setOperand(std::string);
    void setHasPeriodTyped(bool);
    void setIsNegative(bool);
private:
    std::string operand;
    bool HasPeriodTyped = false;
    bool IsNegative = false;
};
