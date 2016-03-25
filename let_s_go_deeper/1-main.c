#include <stdio.h>
int power(int x, int y);

int main(void)
{
  int r;

  r = power(1, 10);
  printf("%d\n", r);
  r = power(1024, 0);
  printf("%d\n", r);
  r = power(2, 16);
  printf("%d\n", r);
  r = power(5, 2);
  printf("%d\n", r);
  r = power(5, -2);
  printf("%d\n", r);
  return (0);
}
