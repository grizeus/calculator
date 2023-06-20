#pragma once
#include <array>
#include "Button.hpp"

class InputBoard
{
public:
    InputBoard(ToolsPtr);
    ~InputBoard();

    void AddButton(Coordinate, const std::string&, InputCode, int);
    InputCode CheckInput();

    std::array<Button, 24> GetButtons() const;
private:
    std::array<Button, 24> m_Buttons;
    ToolsPtr m_Drawer;
};
