#include <stdio.h>
int string_to_integer(char *s);

int main(void)
{
  int n;

  n = string_to_integer("98");
  printf("%d\n", n);
  n = string_to_integer("-402");
  printf("%d\n", n);
  n = string_to_integer("        ++++++-----+++++--98");
  printf("%d\n", n);
  n = string_to_integer("--2147483647");
  printf("%d\n", n);
  n = string_to_integer("0");
  printf("%d\n", n);
  n = string_to_integer("-----2147483647 dslsjklf 302942 sd");
  printf("%d\n", n);
  n = string_to_integer("-2147483648");
  printf("%d\n", n);
  n = string_to_integer("342342321474348340952740893572489572024375203745902834758983648");
  printf("%d\n", n);
  n = string_to_integer("Suite 402");
  printf("%d\n", n);
  n = string_to_integer("      +    +   -   -98 Battery Street; San Francisco, CA 94111 - USA         ");
  printf("%d\n", n);
  n = string_to_integer("---++++ - Sui - te -  402 #cisfun :)");
  printf("%d\n", n);
  return (0);
}
