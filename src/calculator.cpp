#include "../include/calculator.hpp"
#include <stdexcept>
#include <iostream>

Calculator::Calculator()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDL failed initialization!\n");
    if (SDL_CreateWindowAndRenderer(m_width, m_height, 0, &m_window, &m_renderer) != 0)
        throw std::runtime_error(SDL_GetError());
    SDL_SetWindowTitle(m_window, "Calculator 3000");
    SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    if (TTF_Init() == -1) 
        throw std::runtime_error(TTF_GetError());
    m_font = TTF_OpenFont("lazy.ttf", 15);
	if (m_font == NULL)
        throw std::runtime_error(TTF_GetError());
}

Calculator::~Calculator()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    TTF_CloseFont(m_font);

    m_renderer = nullptr;
    m_window = nullptr;
    m_font = nullptr;

    TTF_Quit();
    SDL_Quit();
}

int Calculator::Execution()
{
    SDL_Event e;
    for (;;)
    {
        while (SDL_WaitEvent(&e)) 
        {
            switch (e.type) 
            {
            case SDL_MOUSEBUTTONUP:
            {
                auto x = e.button.x * 4 / m_width;
                auto y = e.button.y * 5 / m_height - 1;
                if (x >= 0 && x < 4 && y >= 0 && y < 4)
                {
                    auto ch = symbols[y][x];
                    std::cout << ch << std::endl;
                    if (ch >= '0' && ch <= '9')
                    {
                        if (!IsEmpty)
                        {
                            UserInput.clear();
                            IsEmpty = true;
                        }
                        UserInput += ch;
                    }
                    else
                    {
                        if (Op != '\0')
                        {
                            switch (ch)
                            {
                            case '+':
                            case '-':
                            case '*':
                            case '/':
                            case '%':
                                Op = ch;
                                break;
                            case '=':
                                Op = '\0';
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case SDL_QUIT:
                return 0;
            }
        Draw();
        }
    }
    return 0;
}

void Calculator::Draw()
{

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 0xCF, 0xCF, 0xCF, 0xCF);
    // draw horizontal lines
    for (int i = 1; i < 5; ++i)
        SDL_RenderDrawLine(m_renderer, 0, i * m_height / 5, m_width, i * m_height / 5 );
    // draw vertical lines
    for (int i = 1; i < 4; ++i)
        SDL_RenderDrawLine(m_renderer, i * m_width / 4, m_height / 5, i * m_width / 4, m_height );
    
    SDL_RenderPresent(m_renderer);
}
