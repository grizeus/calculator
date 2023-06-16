#include "Display.hpp"

Display::Display(SDL_Tools* drawer)
    :UI_Element(m_Drawer), 
{
    m_UI.m_Height = 10;
    m_UI.m_Width = 490;
    // m_UI.m_Position = {0.0f, 0.0f};
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