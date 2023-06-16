#pragma once
#include "UI_Element.hpp"

class Display
{
public:
    Display();
    
    void Draw(std::string);
private:
    UI_Element m_UI;
};