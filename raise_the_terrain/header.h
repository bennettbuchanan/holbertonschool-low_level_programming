#include <SDL2/SDL.h>
#include <stdio.h>

void create_window(SDL_Window* window, SDL_Renderer* renderer);
void define_grid(SDL_Renderer*);
void draw_grid(int scale, int n, int x1, int y1, SDL_Renderer* renderer);

int WINDOW_HEIGHT = 720;
int WINDOW_WIDTH = 1260;
