#include <stdio.h>
int shell_comp(char *s1, char *s2);

int main(void)
{
  int r;

  r = shell_comp("main.c", "*.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*a*i*n*.*c*");
  printf("%d\n", r);
  r = shell_comp("main.c", "main.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "ma********************************c");
  printf("%d\n", r);
  r = shell_comp("main.c", "*");
  printf("%d\n", r);
  r = shell_comp("main.c", "***");
  printf("%d\n", r);
  r = shell_comp("main.c", "m.*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "**.*c");
  printf("%d\n", r);
  r = shell_comp("main-main.c", "ma*in.c");
  printf("%d\n", r);
  return (0);
}
