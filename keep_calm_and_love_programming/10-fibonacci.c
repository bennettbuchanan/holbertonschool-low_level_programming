#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 1;
  int c = 0;
  int total = 0;

  while (c < 4000000) {
    a = b;
    b = c;
    c = a + b;
    if (c < 4000000 && c > 1 && c % 2 == 0) {
      total += c;
    }
  }
  printf("%d\n", total);
  return(0);
}
