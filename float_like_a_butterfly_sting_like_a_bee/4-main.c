#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);
void free_grid(int **, int);

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  free_grid(grid, 5);
  return (0);
}
