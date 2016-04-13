#include <stdio.h>
#include <stdlib.h>
char *string_dup(char *);

int main()
{
  char *s;

  s = string_dup("Holberton");
  printf("%s\n", s);
  free(s);
  return (0);
}
