#pragma once
#include "UI_Element.hpp"

class Display {
public:
    Display(ToolsPtr drawer);
    ~Display() { }
    void Draw(const std::string&);
private:
    std::shared_ptr<UI_Element> m_UI_Element;
};
