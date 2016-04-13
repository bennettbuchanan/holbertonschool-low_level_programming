#include <stdlib.h>

void free_grid(int **grid, int x) {
  int i;
  for(i = 0; i < x; i++) {
    free(grid[i]);
  }
  free(grid);
}
