#include <stdio.h>
char uppercase(char);

int main(void)
{
  char c;

  c = uppercase('a');
  printf("%c\n", c);
  c = uppercase('h');
  printf("%c\n", c);
  c = uppercase('A');
  printf("%c\n", c);
  c = uppercase('{');
  printf("%c\n", c);
  return (0);
}
