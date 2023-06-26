#pragma once
#include "UI_Element.hpp"

class Display {
public:
    Display(ToolsPtr drawer);
    ~Display() { }
    void Draw(const std::string&);

    // UI_Element's getters and setters
    int GetWidth() const { return m_UI_Element.GetWidth(); }
    int GetHeight() const { return m_UI_Element.GetHeight(); }
    Coordinate GetPosition() const { return m_UI_Element.GetPosition(); }
    UI_Element::Color GetBackgroundColor() const { return m_UI_Element.GetBackgroundColor(); }
    UI_Element::Color GetContentColor() const { return m_UI_Element.GetContentColor(); }
    UI_Element::Color GetBorderColor() const { return m_UI_Element.GetBorderColor(); }
    UI_Element::Color GetHoverColor() const { return m_UI_Element.GetHoverColor(); }
    ToolsPtr GetTools() const { return m_UI_Element.GetTools(); }

    void SetWidth(int);
    void SetHeight(int);
    void SetPosition(float, float);
    void SetBackgroundColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetContentColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetBorderColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetTools(ToolsPtr);
private:
    UI_Element m_UI_Element;
};
