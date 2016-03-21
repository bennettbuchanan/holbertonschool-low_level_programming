#include <stdio.h>
char *uppercase_string(char *);

int main(void)
{
  char s[] = "Holberton School!\n";
  char *p;

  p = uppercase_string(s);
  printf("%s", p);
  printf("%s", s);
  return (0);
}
