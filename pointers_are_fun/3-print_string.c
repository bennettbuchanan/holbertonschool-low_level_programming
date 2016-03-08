#include "my_functions.h"

void print_string(char *str)
{
  int i;
  /* break out of loop when string reaches 0 in memory */
  for (i = 0; i >= 0; i++) {
    if (str[i] == 0)
      {
	break;
      }
    else
      {
	/* print char of string */
	print_char(str[i]);	
      }
  }
  print_char(str[i]);
}
