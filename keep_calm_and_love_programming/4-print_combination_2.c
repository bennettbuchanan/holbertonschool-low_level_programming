#include "my_functions.h"

/* call print comination function */
void print_combination_2(void)
{
  int i, j;
  /* track the tenths place in var i */
  for (i = 0; i < 10; i++)
    {
      /* track the ones place relative to i in var j */
      for (j = i + 1; j < 10; j++)
	{
	  print_char(i + 48); /* print i plus 48 for digit output */
	  print_char(j + 48); /* print j plus 48 for digit output */
	  /* do not print comma and space after 89 */
	  if (i < 8)
	    {
	      print_char(','); /* print comma */
	      print_char(' '); /* print space */
	    }
	}
    }
}
