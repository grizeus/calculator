#include <iostream>
#include "Calculator.hpp"

int main(int argc, char** argv) 
{
    std::shared_ptr<SDL_Tools> tool(new SDL_Tools());
    if(!tool->ToolsInit())
    {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }
    InputBoard buttons;
    Calculator calculator;
    Display display;
    // TODO init button
    display.Draw();
    buttons.Draw();
    while (true)
    {
        InputCode input = buttons.CheckInput();
        // TODO checkinput should check hover button state, buttonpressed, keypressed
        calculator.UserInput();
        if input == quit_code
            break;
    }
    return 0;
}
