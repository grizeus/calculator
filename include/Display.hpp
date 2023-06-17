#pragma once
#include "UI_Element.hpp"

class Display : public UI_Element
{
public:
    Display(SDL_Tools* drawer);
    void Hover(bool) override;
    bool Draw(const std::string&) override;
};