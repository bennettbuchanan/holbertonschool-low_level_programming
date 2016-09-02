#include "header.h"

/**
 * main - The main function
 * @void: Void.
 * Description: Initialize SDL instance, call create window function,
 * and when complete, destroy window and quit SDL.
 */
int main(void)
{
        /* The window we'll be rendering */
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        /* Initialize SDL */
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
                printf("SDL could not initialize! SDL_Error: %s\n",
                       SDL_GetError());
        }
        else
        {
                create_window(window, renderer);
        }

        /* Destroy window */
        SDL_DestroyWindow(window);

        /* Quit SDL subsystems */
        SDL_Quit();
}

/**
 * create_window - Create a new window.
 * @window: The SDL window to create.
 * @renderer: The SDL rendering.
 * Description: Create the window and rendering of SDL. If there are
 * no errors in that process, then define the grid.
 */
void create_window(SDL_Window *window, SDL_Renderer *renderer)
{
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                  WINDOW_HEIGHT, 0);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_PRESENTVSYNC);

        if (window == NULL)
        {
                printf("Window could not be created! SDL_Error: %s\n",
                       SDL_GetError());
        }
        else if (renderer == NULL)
        {
                SDL_DestroyWindow(window);
                printf("Window could not be created! SDL_Error: %s\n",
                       SDL_GetError());
        }
        else
        {
                define_grid(renderer);
        }
}

/**
 * define_grid - Set initial values for the grid to be generated.
 * @renderer: The SDL rendering.
 * Description: Set initial values for the grid and color of the
 * rendering. Begin an infinite loop of the window, calling draw_grid
 * with the parameters defined previously.
 */
void define_grid(SDL_Renderer *renderer)
{
        /* int scale = 100; */
        /* int n = 8; */
        /* int x1 = WINDOW_WIDTH / 2 - (scale * n / 4) - (scale); */
        /* int y1 = WINDOW_HEIGHT / 2 - (scale * n / 4); */
        /* draw_grid(scale, n, x1, y1, x1 - 50, y1 + 50, renderer); */

        int n = 10;
        int scale = 64;
        int i;
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = scale;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);

        for (i = 0; i < n; i++) {

                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

                x2 += scale;
                x1 += scale;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay( 2000 );
}
