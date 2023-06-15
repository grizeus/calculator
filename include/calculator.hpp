#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Calculator 
{
public:
    Calculator();
    ~Calculator();
    int Execution();
private:
    int m_width = 720 * 5 / 4;
    int m_height = 720;

    const char* symbols[4] = {
        "789/",
        "456*",
        "123-",
        "0.=+"
    };
    std::string UserInput;
    char Op = 0;
    std::string Result;
    bool IsEmpty = true;

    SDL_Renderer* m_renderer;
    SDL_Window* m_window;
    TTF_Font* m_font;

    void Draw();
}; 
