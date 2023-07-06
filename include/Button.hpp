#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"

enum InputCode {
    Unspecify = 0,
    PlusMinus, Zero, Period, Equal,
    One, Two, Three, Plus,
    Four, Five, Six, Minus,
    Seven, Eight, Nine, Asterisk,
    Inverse, Square, SquareRoot, Slash,
    Percent, ClearEntry, Clear, Backspace
};

class Button {
public:
    Button() = default;
    Button(Coordinate, ToolsPtr, const std::string&, InputCode);
    ~Button() { }

    void Draw();

    inline void SetHover(bool hover) { m_IsHover = hover; }
    inline bool IsHover() const { return m_IsHover; }
    inline InputCode GetCode() const { return m_Code; }
    inline std::string GetSymbol() const { return m_Symbol; }
    inline UI_Element GetElement() const { return m_UI_Element; }

    // UI_Element's getters and setters
    inline int GetWidth() const { return m_UI_Element.GetWidth(); }
    inline int GetHeight() const { return m_UI_Element.GetHeight(); }
    inline Coordinate GetPosition() const { return m_UI_Element.GetPosition(); }
    inline UI_Element::Color GetBackgroundColor() const { return m_UI_Element.GetBackgroundColor(); }
    inline UI_Element::Color GetContentColor() const { return m_UI_Element.GetContentColor(); }
    inline UI_Element::Color GetBorderColor() const { return m_UI_Element.GetBorderColor(); }
    inline UI_Element::Color GetHoverColor() const { return m_UI_Element.GetHoverColor(); }
    inline ToolsPtr GetTools() const { return m_UI_Element.GetTools(); }

    inline void SetHeight(int height) { m_UI_Element.SetHeight(height); }
    inline void SetWidth(int width) { m_UI_Element.SetWidth(width); }
    inline void SetPosition(float x, float y) { m_UI_Element.SetPosition(x, y); }
    inline void SetBorderColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBorderColor(r, g, b, a); }
    inline void SetBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetBackgroundColor(r, g, b, a); }
    inline void SetHoverColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetHoverColor(r, g, b, a); }
    inline void SetContentColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { m_UI_Element.SetContentColor(r, g, b, a); }
    inline void SetTools(ToolsPtr tools) { m_UI_Element.SetTools(tools); }
private:
    UI_Element m_UI_Element;
    std::string m_Symbol;
    InputCode m_Code;
    bool m_IsHover;
};
