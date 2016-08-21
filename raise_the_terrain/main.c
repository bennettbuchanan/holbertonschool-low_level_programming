#include <SDL2/SDL.h>
#include <stdio.h>

void create_window(SDL_Window* window, SDL_Renderer* renderer);
void draw_window(SDL_Renderer* renderer);

int main(void)
{
    //The window we'll be rendering to
    SDL_Window* window;
    SDL_Renderer* renderer;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        create_window(window, renderer);
    }

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}

void create_window(SDL_Window* window, SDL_Renderer* renderer)
{
    int SCREEN_WIDTH = 1000;
    int SCREEN_HEIGHT = 700;

    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);

    if(window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n",
               SDL_GetError());
    }
    else if (renderer == NULL) {
        SDL_DestroyWindow(window);
        printf("Window could not be created! SDL_Error: %s\n",
               SDL_GetError());
    }
    else
    {
        draw_window(renderer);
    }
}

void draw_window(SDL_Renderer* renderer)
{
    int startingPoint = 500;
    int endingPoint = 280;

    SDL_Point points[2];

    points[0].x = 120;
    points[0].y = 60;

    points[1].x = 40;
    points[1].y = endingPoint + 10;


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, 10, 10, 600, 600);
    SDL_RenderDrawLines(renderer, points, 2);
    SDL_RenderPresent(renderer);

    SDL_Delay(7000);
}
