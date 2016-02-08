#include "my_functions.h"
#include <stdio.h>

void print_number(int n)
{
  if (n == 98)
    {
      int t = 98;
      print_char(t);
    }
  print_char(n);
  printf("%d\n", n);
}
