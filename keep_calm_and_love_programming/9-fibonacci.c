#include <stdio.h>
/* print the first 50 Fibonacci numbers, starting with 1 and 2 */
int main(void) {
  long int a = 0;
  long int b = 1;
  long int c = 0;
  int i;

  printf("%ld, ", b); /* print 1 initially to avoid to printing 1 twice */
  for (i = 0; i <= 50; i++) {
    a = b;
    b = c;
    c = a + b;
    if (i > 1 && i < 50) {
      printf("%ld, ", c); /* print Fibonacci numbers greater than 1 */
    }
    if (i > 1 && i == 50) {
      printf("%ld\n", c); /* print Fibonacci numbers greater than 1 */
    }
  }
  return(0);
}
