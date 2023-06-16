#pragma once
#include "UI_Element.hpp"

class Display : public UI_Element
{
public:
    Display(SDL_Tools* drawer);
    
    void Draw(std::string);
};