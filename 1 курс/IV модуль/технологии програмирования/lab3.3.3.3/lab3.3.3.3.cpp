#include <iostream>
#include "SDL.h"
#include <string>
#include <ctime>
#include <math.h>
using namespace std;


//#include "VM.h"
class Engine 
{
private:
    bool flagToExit = false;
    int height;
    int width; // размер окна в пикселях
    string value;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    int a, b;

    int Init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        {   
            cout << SDL_GetError() << "\n";
            return -2;
        }

        window = SDL_CreateWindow("Laba4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width,
            SDL_WINDOW_VULKAN | SDL_WINDOW_BORDERLESS);
        if (window == NULL)
        {
            cout << SDL_GetError() << "\n";
            return -3;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        return 10;
    };

    void Render()
    {
        cout << "Press 1 to display the figure. " << endl << "Press 2 to rotate the figure" << endl<<"Press 3 to largen the figure"<<endl;
        cin >> b;
        switch (b)
        {
        case 2: //rotate
            cout << "Enter the angle: ";
            cin >> a;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, (150 * cos(a) - 150 * sin(a)), (150 * sin(a) - 150 * cos(a)), (250 * cos(a) - 350 * sin(a)), (250 * sin(a) - 350 * cos(a)));
            SDL_RenderDrawLine(renderer, (250 * cos(a) - 350 * sin(a)), (250 * sin(a) - 350 * cos(a)), (350 * cos(a) - 150 * sin(a)), (350 * sin(a) - 150 * cos(a)));
            SDL_RenderDrawLine(renderer, (350 * cos(a) - 150 * sin(a)), (350 * sin(a) - 150 * cos(a)), (150 * cos(a) - 150 * sin(a)), (150 * sin(a) - 150 * cos(a)));
            SDL_RenderDrawLine(renderer, 0, 0, 0, 700);
            SDL_RenderDrawLine(renderer, 0, 0, 700, 0);
            SDL_RenderPresent(renderer);
            break;

        case 1: //display
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, 150, 150, 250, 350);
            SDL_RenderDrawLine(renderer, 250, 350, 350, 150);
            SDL_RenderDrawLine(renderer, 350, 150, 150, 150);
            SDL_RenderDrawLine(renderer, 0, 0, 0, 700);
            SDL_RenderDrawLine(renderer, 0, 0, 700, 0);
            SDL_RenderPresent(renderer);
            break;

        case 3:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, 150, 150, 250*2, 350*2);
            SDL_RenderDrawLine(renderer, 250*2, 350*2, 350*2, 150*2);
            SDL_RenderDrawLine(renderer, 350*2, 150*2, 150, 150);
            SDL_RenderDrawLine(renderer, 0, 0, 0, 700);
            SDL_RenderDrawLine(renderer, 0, 0, 700, 0);
            SDL_RenderPresent(renderer);

        default:
            break;
        }
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
                cout << "i'm here"
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

    void Update() {
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

    ~Engine() {};

    void Run()
    {
        Init();
        while (true)
        {
            PollsEvent();
            Update();
            Render();
        }
        SDL_DestroyRenderer(renderer);
        cout << "renderer memory finalized"
            << "\n";
        SDL_DestroyWindow(window);
        cout << "window memory finalized"
            << "\n";
        SDL_Quit();
        cout << "SDL memory finalized"
            << "\n";
    }
};

int main(int argc, char* argv[])
{
    Engine visualMath = Engine(800, 800);
    visualMath.Run();
    return 0;
}