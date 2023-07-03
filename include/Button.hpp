#pragma once
#include "SDL_Tools.hpp"
#include "UI_Element.hpp"

enum InputCode {
    Unspecify = 0,
    Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Plus, Minus, Asterisk, Slash, Percent, Inverse, Square, SquareRoot,
    Clear, ClearEntry, Period, PlusMinus, Equal, Backspace
};

class Button {
public:
    Button() = default;
    Button(Coordinate, ToolsPtr, const std::string&, InputCode);

    ~Button() { }

    void Draw();
    InputCode Click();

    void SetHover(bool);

    bool IsHover() const;
    UI_Element GetElement() const;
    InputCode GetCode() const;
    std::string GetSymbol() const;
    
    // UI_Element's getters and setters
    inline int GetWidth() const { return m_UI_Element.GetWidth(); }
    inline int GetHeight() const { return m_UI_Element.GetHeight(); }
    inline Coordinate GetPosition() const { return m_UI_Element.GetPosition(); }
    inline UI_Element::Color GetBackgroundColor() const { return m_UI_Element.GetBackgroundColor(); }
    inline UI_Element::Color GetContentColor() const { return m_UI_Element.GetContentColor(); }
    inline UI_Element::Color GetBorderColor() const { return m_UI_Element.GetBorderColor(); }
    inline UI_Element::Color IsHoverColor() const { return m_UI_Element.IsHoverColor(); }
    inline ToolsPtr GetTools() const { return m_UI_Element.GetTools(); }

    void SetWidth(int); 
    void SetHeight(int);
    void SetPosition(float, float);
    void SetBackgroundColor(uint8_t, uint8_t, uint8_t, uint8_t); 
    void SetContentColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetBorderColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetHoverColor(uint8_t, uint8_t, uint8_t, uint8_t);
    void SetTools(ToolsPtr); 
private:
    UI_Element m_UI_Element;
    std::string m_Symbol;
    InputCode m_Code;
    bool m_IsHover;
};
