#include <stdio.h>
/* find and print the largest prime factor of the number 612852475143 */
int main()
{   
  long int n = 612852475143;
  int divisor = 2;
  long int result = 0;
  /* continue loop while n is greater than 1 */
  while (n > 1) {
    if (divisor > result) {
      result = divisor; /* store result as divisor */
    }
    if (n % divisor == 0) {
      n /= divisor; /* store n as the result of n divided by divisor */ 
    }
    if (n % divisor != 0) {
      divisor++; /* increment by 1 until reaching next prime number */
    }
  }
  /* print result and a newline */
  printf("%ld\n", result);
  return (0);
}
