#include <exception>
#include <iostream>
#include "../include/Calculator.hpp"
#include "../include/Button.hpp"
#include "../include/Display.hpp"
#include "../include/InputBoard.hpp"
#include "../include/UI_Element.hpp"
#include "../include/SDL_Tools.hpp"
#include "SDL_render.h"

int main(int argc, char** argv) {
    ToolsPtr tool(new SDL_Tools());
    if(!tool->ToolsInit()) {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }
    Calculator calculator(tool);
    InputBoard buttons(tool);
    // Display display(tool);
    // calculator.SetDisplay(std::make_shared<Display>(display));
    calculator.DisplayResult();
    // display.Draw(" ");
    // iterators
    for (int i = 0; i < buttons.GetButtons().size(); ++i)
        buttons.GetButtons()[i].Draw();
    SDL_RenderPresent(tool->m_Renderer);

    while (true) {

        // for (int i = 0; i < buttons.GetButtons().size(); ++i)
            // buttons.GetButtons()[i].FinalDraw();
    
        InputCode input = buttons.CheckInput();
        calculator.Processing(input);

    try {
        calculator.DisplayResult();
    SDL_RenderPresent(tool->m_Renderer);
    }catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    }
    return 0;
    
}
