#include <stdio.h>

int main(void) {
  long int a = 0;
  long int b = 1;
  long int c = 0;
  int i;

  printf("%ld, ", b);
  for (i = 0; i <= 50; i++) {
    a = b;
    b = c;
    c = a + b;
    if (c > 1) {
      printf("%ld, ", c);
    }
  }

  printf("\n");
  return(0);
}
