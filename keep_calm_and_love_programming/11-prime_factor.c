#include <stdio.h>

int main()
{   
  long int n = 612852475143;
  int divisor = 2;
  int result = 0;

  while (n > 1) {
    if (divisor > result) {
      result = divisor;
    }
    if (n % divisor == 0) {
      n /= divisor;
      printf("%d\n", divisor);
    }
    if (n % divisor != 0) {
      divisor++;
    }
  }
  printf("the biggest divisor is: %d\n", result);
  return (0);
}
