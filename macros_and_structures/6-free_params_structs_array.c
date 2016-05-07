#include <stdio.h>
#include <stdlib.h>
#include "param_struct.h"

void free_params_structs_array(struct Param *array)
{
  int i, j;

  /* Free all allocated places in memory. */

  for(i = 0; array[i].tab != NULL; ++i) {
    free(array[i].tab);
  }

  for(j = 0; j < 10000; ++j) {
    free(array[0].tab[j]);
  }

  for(j = 0; j < 10000; ++j) {
    free(array[1].tab[j]);
  }

  free(array);
}
