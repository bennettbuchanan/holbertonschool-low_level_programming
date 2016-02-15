#include "my_functions.h"

/* call print comination function */
void print_combination_4(void)
{
  int i, j, k, l;
  for (i = 0; i < 10; i++)/* track the tenths place */
    { /* track the ones place */
      for (j = 0; j < 10; j++)
	{ /* second pair of numbers relative to first pair */
	  for (k = i; k < 10; k++)
	    { /* ones place initializes at var j + 1 */
	      for (l = j + 1; l < 10; l++)
		{ print_char(i + 48);
		  print_char(j + 48);
		  print_char(' ');
		  print_char(k + 48);
		  print_char(l + 48);
		  if (i == 9 && j == 8)/* do not print after 98 */
		    {}
		  else
		    { print_char(',');
		      print_char(' ');}
		}
	    }
	}
    }
}
