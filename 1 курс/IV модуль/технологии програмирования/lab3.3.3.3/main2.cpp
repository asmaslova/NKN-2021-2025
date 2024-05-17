#include <iostream>
#include "SDL.h"

//#include "VM.h"
class Engine
{
private:
    bool flagToExit = false;
    int height;
    int width; // размер окна в пикселях
    std::string value;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    int Init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        {
            std::cout << SDL_GetError() << "\n";
            return -2;
        }

        window = SDL_CreateWindow("Laba3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width,
                                  SDL_WINDOW_VULKAN | SDL_WINDOW_BORDERLESS);
        if (window == NULL)
        {
            std::cout << SDL_GetError() << "\n";
            return -3;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        return 10;
    };

    void Render()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
        SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
        SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
        SDL_RenderPresent(renderer);
    };

    void PollsEvent()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            flagToExit = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                flagToExit = true;
                break;
            case SDLK_SPACE:
                std::cout << "i'm here"
                          << "\n";
                break;
            
            default:
                break;
            
            }
            break;
        default:
            break;
        }
    };

    void Update(){
        /*
         * В данной функции реализуется логика вызова методов
         * для операций над матрицами и векторами.
         *
         *
         * */
    };

public:
    Engine(int height, int width)
    {
        this->height = height;
        this->width = width;
    };

    ~Engine(){};

    void Run()
    {
        Init();
        while (!flagToExit)
        {
            PollsEvent();
            Update();
            Render();
        }
        SDL_DestroyRenderer(renderer);
        std::cout << "renderer memory finalized"
                  << "\n";
        SDL_DestroyWindow(window);
        std::cout << "window memory finalized"
                  << "\n";
        SDL_Quit();
        std::cout << "SDL memory finalized"
                  << "\n";
    }
};

int main(int argc, char *argv[])
{

    Engine visualMath = Engine(600, 800);
    visualMath.Run();
    return 0;
}