#include "Display.hpp"

Display::Display(SDL_Tools* drawer)
    : UI_Element(drawer) 
{
    SetHeight(10);
    SetWidth(490);
    SetPosition(0.0f, 0.0f);
    SetBackgroundColor(0xCF, 0xCF, 0xCF, 0xCF);
    SetBorderColor( 0xCF, 0xCF, 0xCF, 0xFF);
    SetHoverColor (0xCF, 0xCF, 0xCF, 0xCF);
    SetContentColor (0x00, 0x00, 0x00, 0xFF); // black
}
// uint32_t color = 0xFF;
// color = color << 8;
// color = color | 0xA5;
// color = color << 8;
// color = color | 0x12;
