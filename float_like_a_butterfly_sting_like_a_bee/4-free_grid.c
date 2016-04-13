#include <stdlib.h>

int **alloc_grid(int width, int height) {
  int i, j;
  int **grid;

  grid = malloc(sizeof(int **) * width);
  if (grid == NULL) {
    return (NULL);
  }
  for (i = 0; i < height; i++) {
    grid[i] = malloc(sizeof(int));
    if (grid[i] == NULL) {
      return (NULL);
    }
  }
  /* Assign decimals to the grid array */
  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      grid[i][j] = 0;
    }
  }

  return (grid);
  free(grid);
}

void free_grid(int **grid, int x) {
  int i;
  for(i = 0; i < x; i++) {
    free(grid[i]);
  }
  free(grid);
}
