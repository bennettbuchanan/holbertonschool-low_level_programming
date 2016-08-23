#include "header.h"

/**
 * main - The main function
 * @void: Void.
 * Description: Initialize SDL instance, call createwindow function,
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
	int scale = 100;
	int n = 8;
	int x1 = WINDOW_WIDTH / 2 - (scale * n / 4) - (scale);
	int y1 = WINDOW_HEIGHT / 2 - (scale * n / 4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);

	while (1)
	{
		draw_grid(scale, n, x1, y1, x1 - 50, y1 + 50, renderer);
		SDL_RenderPresent(renderer);
	}
}

/**
 * draw_grid - Draw the grid based on coordinates.
 * @scale: The scale of the squares.
 * @n: The number of grid lines.
 * @x1: x1 coordinate of the line.
 * @y1: y1 coordinate of the line.
 * @x2: x2 coordinate of the line.
 * @y2: y2 coordinate of the line.
 * @renderer: The SDL rendering.
 * Description: Draws a grid based on the parameter locations passed
 * to the function. The grid can be altered based on values passed to
 * the alt variable. These altitude values similate changed altitudes
 * of a landscape.
 */
void draw_grid(int scale, int n, int x1, int y1, int x2, int y2,
	       SDL_Renderer *renderer)
{
	int i, j, tmp;
	int alt[8][8] = {
		{120, 60, 0, 0, 0, 0, 0, 0}, {20, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 20, 20, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, -20, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}, {20, 0, 0, 0, 0, 0, 0, 0}
	};
	tmp = scale;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i + 1 != n)
			{
				SDL_RenderDrawLine(renderer, x1 +
						   scale, y1 - alt[i][j], x2 +
						   scale, y2 - alt[i + 1][j]);
			}
			if (j + 1 != n && i + 1 != n)
			{
				SDL_RenderDrawLine(renderer, x2 + scale, y2 -
						   alt[i + 1][j], x2 + scale +
						   tmp, y2 - alt[i + 1][j + 1]);
			}
			if (i == 0 && j + 1 != n)
			{
				SDL_RenderDrawLine(renderer, x1 + scale, y1 -
						   alt[i][j], x1 + scale +
						   tmp, y1 - alt[i][j + 1]);
			}
			scale += tmp;
		}
		scale = tmp;
		x1 -= scale / 2;
		x2 -= scale / 2;
		y1 += scale / 2;
		y2 += scale / 2;
	}
}


/* {120, 60, 40, 60, 20, -20, -80, -120}, */
/* {40, 20, 30, 30, -10, -40, -90, -110}, */
/* {20, 30, 10, 06, -6, -20, -26, -90}, */
/* {00, -6, 10, 10, -6, -20, -20, -40}, */
/* {-20, -20, -18, -14, -40, -20, -20, -30}, */
/* {-10, -10, -10, -10, -8, -20, -20, -30}, */
/* {20, 10, 10, 10, 10, 04, 10, -10}, */
/* {30, 24, 24, 22, 20, 18, 14, 16}, */
