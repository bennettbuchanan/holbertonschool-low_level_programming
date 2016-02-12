#include "my_functions.h"

/* call print comination function */
void print_combination_3(void)
{
  int i, j, k;
  /* track the hundreds place in var i */
  for (i = 0; i < 10; i++)
    {
      /* track the tens place relative to i in var j */
      for (j = i + 1; j < 10; j++)
	{
	  /* track the tens place relative to i in var j */
	  for (k = j + 1; k < 10; k++)
	    {
	      print_char(i + 48);
	      print_char(j + 48);
	      print_char(k + 48);
	      /* do not print comma and space after 789 */
	      if (i < 7)
		{
		  print_char(',');
		  print_char(' ');
		}
	    }
	}
    }
}
