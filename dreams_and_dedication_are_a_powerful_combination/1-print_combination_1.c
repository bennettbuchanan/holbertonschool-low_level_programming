#include "my_functions.h"

/* call print_combination function */
void print_combination_1(void)
{
  int i;
  /* loop through ten times */
  for (i = 0; i < 10; i++)
    {
      print_char(i + 48);
      /* do not print comma and space after 9 */
      if (i < 9)
	{
	  print_char(',');
	  print_char(' ');
	}
    }
}
