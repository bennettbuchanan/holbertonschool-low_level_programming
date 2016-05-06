#include "param_struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "limits.h"

void print_params_structs_array(struct Param *array)
{
  int i, j;

  for(i = 0; array[i].str != NULL; ++i) {
    printf("%s\n", array[i].copy);
    printf("%d\n", array[i].length);

    /* Print each word in the string. */
      for(j = 0; array[i].tab[j] != NULL; ++j) {
        printf("%s", array[i].tab[j]);
        if (array[i].tab[j + 1] != NULL) {
          printf(", ");
        }
      }
    printf("\n");
  }
}
