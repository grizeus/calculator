#include "../include/UI_Element.hpp"

UI_Element::UI_Element(ToolsPtr drawer)
        : m_Drawer(drawer)
{ }

bool UI_Element::Intersect(float x, float y) {
    if (x < (m_Position.first + m_Width) && x > m_Position.first
        && y < (m_Position.second + m_Height) && y > m_Position.second)
        return true;
    return false;
}

void UI_Element::SetHeight(int h) { m_Height = h; }
void UI_Element::SetWidth(int w) { m_Width = w; }
void UI_Element::SetPosition (float x, float y) { m_Position = std::make_pair(x, y); }
void UI_Element::SetBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { 
    m_BackgroundColor.red = r; m_BackgroundColor.green = g; m_BackgroundColor.blue = b; m_BackgroundColor.alpha = a; 
}

void UI_Element::SetHoverColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    m_HoverBackgroundColor.red = r; m_HoverBackgroundColor.green = g; m_HoverBackgroundColor.blue = b; m_HoverBackgroundColor.alpha = a;
}

void UI_Element::SetBorderColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    m_BorderColor.red = r; m_BorderColor.green = g; m_BorderColor.blue = b; m_BorderColor.alpha = a;
}

void UI_Element::SetContentColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    m_ContentColor.red = r; m_ContentColor.green = g; m_ContentColor.blue = b; m_ContentColor.alpha = a;
}

void UI_Element::SetTools(ToolsPtr drawer) { m_Drawer = drawer; }