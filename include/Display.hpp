#pragma once
#include "UI_Element.hpp"

class Display : public UI_Element
{
public:
    Display(ToolsPtr drawer);
    void Hover(bool) override;
    bool Draw(const std::string&) override;
};
