#pragma once
#include <array>
#include "Button.hpp"

class InputBoard
{
public:
// TODO add buttons in comstructor
    InputBoard();
    ~InputBoard();

    bool AddButton(std::shared_ptr<Button>);
    InputCode CheckInput();
private:
    std::array<std::shared_ptr<Button>, 24> m_Buttons;
};
