#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
char *int_to_string(int);

int main(void)
{
  char *str;

  str = int_to_string(98888);
  printf("%s\n", str);
  free(str);
  str = int_to_string(992);
  printf("%s\n", str);
  free(str);
  str = int_to_string(-12);
  printf("%s\n", str);
  free(str);
  str = int_to_string(0);
  printf("%s\n", str);
  free(str);
  str = int_to_string(INT_MAX);
  printf("%s\n", str);
  free(str);
  str = int_to_string(INT_MIN);
  printf("%s\n", str);
  free(str);
  return (0);
}
