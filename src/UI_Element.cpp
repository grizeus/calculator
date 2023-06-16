#include "UI_Element.hpp"

UI_Element::UI_Element()
    :
{

}
// void UI_Element::Draw(std::string string)
// {
//     // draw with ttf whenever it is
// }

// void UI_Element::Hover(bool IsHover)
// {
//     if (IsHover == true)
//         draw hover;
// }

UI_Element::UI_Element(int height, int width, coordinate position, u64 backgrnd, u64 hover,
                       u64 border, u64 content) : m_Height(height)
                                                , m_Width(width)
                                                , m_Position(position)
                                                , m_BackgroundColor(backgrnd)
                                                , m_HoverBackgroundColor(hover)
                                                , m_BorderColor(border)
                                                , m_ContentColor(content)
{ }