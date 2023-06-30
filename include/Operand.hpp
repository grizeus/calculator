#pragma once
#include <string>

class Operand {
public:
    Operand();
    Operand(std::string);
    Operand(const Operand&);
    Operand& operator=(const Operand&);
    ~Operand();

    std::string getOperand() const;
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
