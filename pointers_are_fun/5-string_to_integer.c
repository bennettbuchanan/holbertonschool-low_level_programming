#include "my_functions.h"
#include <unistd.h>
#include <stdio.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

int string_to_integer(char *s)
{
  int i, temp;
  int n = 0;
  int isNegative = 0;
  /* break out of loop when string reaches 0 in memory */
  for (i = 0; i >= 0; i++) {
    temp = i - 1;

    if (s[i] == 0)
      {
	break;
      }
    else if (s[i] <= 47 || s[i] >= 58)
      {
	if (s[i] == 45) {
	  isNegative += 1;
	}
	if (s[temp] > 47 && s[temp] < 58) {
	  break;
	}
      }
    else if (s[i] > 47 && s[i] < 58)
      {
	if (isNegative % 2 != 0)
	  {
	    printf("%c", 45);
	  }
	n += 1;
	printf("%c", s[i]);
      }
  }
  return (0);
}
