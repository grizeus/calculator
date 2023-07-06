#pragma once
#include "UI_Element.hpp"

class Display {
public:
    Display();
    Display(ToolsPtr drawer);
    ~Display() { }
    void Draw(const std::string&);

    // UI_Element's getters and setters
    inline int GetWidth() const { return m_UI_Element.GetWidth(); }
    inline int GetHeight() const { return m_UI_Element.GetHeight(); }
    inline Coordinate GetPosition() const { return m_UI_Element.GetPosition(); }
    inline UI_Element::Color GetBackgroundColor() const { return m_UI_Element.GetBackgroundColor(); }
    inline UI_Element::Color GetContentColor() const { return m_UI_Element.GetContentColor(); }
    inline UI_Element::Color GetBorderColor() const { return m_UI_Element.GetBorderColor(); }
    inline ToolsPtr GetTools() const { return m_UI_Element.GetTools(); }

    inline void SetWidth(int width) { m_UI_Element.SetWidth(width); }
    inline void SetHeight(int height) { m_UI_Element.SetHeight(height); }
    inline void SetPosition(float x, float y) { m_UI_Element.SetPosition(x, y); }
    inline void SetBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBackgroundColor(r, g, b, a); }
    inline void SetContentColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetContentColor(r, g, b, a); }
    inline void SetBorderColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBorderColor(r, g, b, a); }

private:
    UI_Element m_UI_Element;
};
