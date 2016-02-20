#include <stdio.h>

int main(void) {
  long int a = 0;
  long int b = 1;
  long int c = 0;
  long int d = 123456789;
  int i;

  printf("%ld, ", b);
  for (i = 0; i <= 102; i++) {
    a = b;
    b = c;
    c = a + b;
    if (c > 1 && c < 14930352) {
      printf("%ld, ", c);
    }
    if (c > 14930352) {
      printf("%ld, ", d);
    }
  }

  printf("\n");
  return(0);
}
