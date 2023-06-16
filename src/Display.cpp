#include "Display.hpp"

Display::Display()
{
    m_UI.m_Height = 10;
    m_UI.m_Width = 490;
    m_UI.m_Position = {0.0f, 0.0f};
    m_UI.m_BackgroundColor = 0xCF, 0xCF, 0xCF, 0xCF;
    m_UI.m_HoverBackgroundColor = 0xCF, 0xCF, 0xCF, 0xCF;
    m_UI.m_BorderColor = 0xCF, 0xCF, 0xCF, 0xCF;
    m_UI.m_ContentColor = 0xCF, 0xCF, 0xCF, 0xCF;
}