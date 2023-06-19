#pragma once
#include <array>
#include "Button.hpp"
// #include "UI_Element.hpp"

class InputBoard
{
public:
// TODO add buttons in costructor
    InputBoard(ToolsPtr);
    ~InputBoard();

    void AddButton(const std::string&, InputCode, int);
    InputCode CheckInput();
private:
    std::array<Button, 24> m_Buttons;
    ToolsPtr m_Drawer;
};
