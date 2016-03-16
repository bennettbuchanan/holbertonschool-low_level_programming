#include <stdio.h>
char *string_copy(char *dest, const char *src);

int main(void)
{
  char s1[98];
  char *p;

  p = string_copy(s1, "First, solve the problem. Then, write the code\n");
  printf("%s", s1);
  printf("%s", p);
  return (0);
}