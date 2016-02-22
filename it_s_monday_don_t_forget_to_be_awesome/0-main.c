#include <stdio.h>
char lowercase(char);

int main(void)
{
  char c;

  c = lowercase('a');
  printf("%c\n", c);
  c = lowercase('h');
  printf("%c\n", c);
  c = lowercase('A');
  printf("%c\n", c);
  c = lowercase('{');
  printf("%c\n", c);
  return (0);
}
