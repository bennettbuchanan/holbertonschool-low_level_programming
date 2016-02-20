#include <limits.h>
#include <stdio.h>
int absolute(int);

int main(void)
{
  int n;

  n = absolute(-1);
  printf("%d\n", n);
  n = absolute(10);
  printf("%d\n", n);
  n = absolute(0);
  printf("%d\n", n);
  n = absolute(INT_MAX);
  printf("%d\n", n);
  n = absolute(INT_MIN + 1);
  printf("%d\n", n);
  n = absolute(INT_MIN);
  printf("%d\n", n);
  return (0);
}
