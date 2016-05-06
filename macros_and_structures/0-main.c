#include <stdio.h>
#include "0-abs.h"
#include <limits.h>

int main(void)
{
  int i;

  i = -98;
  printf("i=%d, abs(i)=%d\n", i, ABS(i));
  return (0);
}
