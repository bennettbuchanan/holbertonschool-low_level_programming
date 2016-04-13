#include <stdlib.h>

void free_grid(int **grid, int x) {
  int i;
  /* Free memory stored at each element in the array */
  for(i = 0; i < x; i++) {
    free(grid[i]);
  }
  /* Free memory that stored the array pointers */
  free(grid);
}
