#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);
void print_grid(int **grid, int width, int height);

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = 402;
  print_grid(grid, 5, 5);
  return (0);
}
