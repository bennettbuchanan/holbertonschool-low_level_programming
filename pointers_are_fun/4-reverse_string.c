#include "my_functions.h"
#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void reverse_string(char *s)
{
  int i;
  /* find the length of the string */
  for (i = 0; i >= 0; i++) {
    if (s[i] == 0) {     
      break;
    }
  }
  /* subtract 1 from i to not print last character */
  i -= 1;
  /* print the string subtracting from the length index */
  for (; i >= 0; i--) {
    if (i == 0) {     
      break;
    }
    else {
      print_char(s[i]);
    }
  }
  print_char(s[i]);
  print_char('\n');
}
