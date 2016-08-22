#include "header.h"

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
    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                              WINDOW_HEIGHT, 0);

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
    int i, j, tmp;
    int scale = 40;
    int n = 8;
    int x1 = WINDOW_WIDTH / 2;
    int y1 = WINDOW_HEIGHT / 2;
    int x2 = x1 - scale / 2;
    int y2 = y1 + scale / 2;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);

    tmp = scale;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            SDL_RenderDrawLine(renderer, x1 + scale, y1, x2 + scale, y2);
            if (j + 1 != n) {
                SDL_RenderDrawLine(renderer, x2 + scale, y2, x2 + scale +
                                   tmp, y2);
            }
            if (i == 0 && j + 1 != n) {
                SDL_RenderDrawLine(renderer, x1 + scale, y1, x1 + scale +
                                   tmp, y1);
            }
            scale += tmp;
        }

        scale = tmp;
        x1 -= scale / 2;
        x2 -= scale / 2;
        y1 += scale / 2;
        y2 += scale / 2;
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
}
