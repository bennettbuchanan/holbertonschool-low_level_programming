#include <stdlib.h>

/* this function frees a grid of chars (array of strings) */
void free_grid(char **grid, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(grid[i]);
	free(grid);
}
