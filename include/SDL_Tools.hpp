#pragma once
#include <SDL2/SDL.h>
#include <stdexcept>
#include <SDL2/SDL_ttf.h>

struct SDL_Tools
{
    bool ToolsInit();
    void ToolsQuit();

    int m_WindowWidth = 498; // win ref
    int m_WindowHeight = 501; // win ref
    
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    // SDL_Surface* m_Surface; // delete later mb
    TTF_Font* m_Font;
    SDL_Texture* m_Texture;
};
