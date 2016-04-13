#include <stdlib.h>
#include <unistd.h>

int **alloc_grid(int width, int height) {
  int i, j;
  int **grid;

  grid = malloc(sizeof(int **) * width);
  if (grid == NULL) {
    return (NULL);
  }
  for (i = 0; i < height; i++) {
    grid[i] = malloc(sizeof(int) * height);
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
}
