#include "UI_Element.hpp"

UI_Element::UI_Element(int height, int width, coordinate position, Color backgrnd, Color hover,
                       Color border, Color content, SDL_Tools* drawer) : m_Height(height)
                                                , m_Width(width)
                                                , m_Position(position)
                                                , m_BackgroundColor(backgrnd)
                                                , m_HoverBackgroundColor(hover)
                                                , m_BorderColor(border)
                                                , m_ContentColor(content)
                                                , m_Drawer(drawer)
{ }