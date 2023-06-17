#include <iostream>
#include "Calculator.hpp"
#include "UI_Element.hpp"

int main(int argc, char** argv) 
{
    Tools tool(new SDL_Tools());
    if(!tool->ToolsInit())
    {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }
    InputBoard buttons;
    Calculator calculator;
    Display display(tool);
    // TODO init button
    display.Draw("0");
    buttons.Draw();
    while (true)
    {
        InputCode input = buttons.CheckInput();
        // TODO checkinput should check hover button state, buttonpressed, keypressed
        calculator.UserInput();
        if input == quit_code
            break;
    }
    tool->ToolsQuit();
    return 0;
}
