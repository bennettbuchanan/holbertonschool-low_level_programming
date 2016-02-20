#include <stdio.h>
/* print sum of even-valued terms of Fibonacci numbers under 4,000,000 */
int main(void) {
  int a = 0;
  int b = 1;
  int c = 0;
  int total = 0;
  /* set condition while c is below 4,000,000 */ 
  while (c < 4000000) {
    a = b;
    b = c;
    c = a + b;
    if (c < 4000000 && c > 1 && c % 2 == 0) {
      total += c; /* add total to itself plus c */
    }
  }
  /* print the total and a newline */
  printf("%d\n", total);
  return(0);
}
