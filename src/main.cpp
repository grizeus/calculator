#include <iostream>
#include "../include/Calculator.hpp"
#include "../include/Button.hpp"
#include "../include/Display.hpp"
#include "../include/InputBoard.hpp"
#include "../include/UI_Element.hpp"
#include "../include/SDL_Tools.hpp"

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
    display.Draw("0");
    for (int i = 0; i < buttons.GetButtons().size(); ++i)
        buttons.GetButtons()[i].Draw("");
    while (true)
    {
        InputCode input = buttons.CheckInput();
        calculator.Processing(input);
        calculator.DisplayResult();
    }
    return 0;
}
