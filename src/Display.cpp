#include "Display.hpp"

Display::Display(SDL_Tools* drawer)
    :UI_Element(m_Drawer), 
{
    SetHeight(10);
    SetWidth(490);
    SetCoordinate(0.0f, 0.0f);
    // SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    Color b = 0xCF, 0xCF, 0xCF, 0xCF;
    SetBorderColor(0x00, );
    // m_UI.m_BackgroundColor = {0xCF, 0xCF, 0xCF, 0xCF};
    // m_UI.m_HoverBackgroundColor = 0xCF, 0xCF, 0xCF, 0xCF;
    // m_UI.m_BorderColor = 0xCF, 0xCF, 0xCF, 0xCF;
    // m_UI.m_ContentColor = 0x00, 0x00, 0x00, 0xFF; // black
}
// uint32_t color = 0xFF;
// color = color << 8;
// color = color | 0xA5;
// color = color << 8;
// color = color | 0x12;