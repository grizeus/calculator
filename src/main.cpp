#include <exception>
#include <iostream>
#include "../include/Calculator.hpp"
#include "../include/Button.hpp"
#include "../include/Display.hpp"
#include "../include/InputBoard.hpp"
#include "../include/UI_Element.hpp"
#include "../include/SDL_Tools.hpp"

int main(int argc, char** argv) {
    ToolsPtr tool(new SDL_Tools());
    if(!tool->ToolsInit()) {
        std::cout << "Initialization failed" << std::endl;
        return 1;
    }
    Calculator calculator(tool);
    InputBoard buttons(tool);
    calculator.DisplayResult();
    for (auto &button : buttons.GetButtons())
        button.Draw();
    SDL_RenderPresent(tool->m_Renderer);

    while (true) {
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
