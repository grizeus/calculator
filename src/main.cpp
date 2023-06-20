#include <iostream>
#include "Calculator.hpp"
#include "UI_Element.hpp"

int main(int argc, char** argv) 
{
    ToolsPtr tool(new SDL_Tools());
    if(!tool->ToolsInit())
    {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }
    Calculator calculator;
    InputBoard buttons(tool);
    Display display(tool);
    calculator.SetDisplay(std::make_shared<Display>(display));
    // TODO init button
    display.Draw("0");
    for (int i = 0; i < buttons.GetButtons().size(); ++i)
        buttons.GetButtons()[i].Draw("");
    while (true)
    {
        InputCode input = buttons.CheckInput();
        // TODO checkinput should check hover button state, buttonpressed, keypressed
        calculator.UserInput();
        if (input == quit_code)
            break;
    }
    return 0;
}
