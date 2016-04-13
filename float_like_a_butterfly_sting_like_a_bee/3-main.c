#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int **alloc_grid(int, int);
void print_grid(int **grid, int width, int height) {
    int i, j, x;

    /* Print the grid array */
    for (i = 0; i < width; i++) {
      for (j = 0; j < height; j++) {
        x = grid[i][j];
        printf("%d", x);
        if (j != width - 1) {
          printf(",");
          printf(" ");
        }
      }
      printf("\n");
    }
}

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = INT_MIN;
  grid[0][0] = INT_MAX;
  print_grid(grid, 5, 5);
  return (0);
}
