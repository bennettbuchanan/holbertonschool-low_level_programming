#include <stdio.h>
#include <stdlib.h>
#include "str_struct.h"

void free_string_struct(struct String *str)
{
  /* Free the space in memory allocated for the string copy. */
  free(str->str);

  /* Free the space in memory allocated for the Struct. */
  free(str);
}
