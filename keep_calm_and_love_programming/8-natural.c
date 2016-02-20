#include <stdio.h>
/* add the sum of all the multiples of 3 or 5 below 1024 */
int main(void) {
  int n = 1024;
  int total = 0;
 
  for (total = 0; n > 0; n--) {
    if (n % 5 == 0 && n % 3 != 0) {
      total += n; /* store the total as n plus itself */
    }
    if (n % 3 == 0 && n % 5 != 0) {
      total += n; /* store the total as n plus itself */
    }
    if (n % 3 == 0 && n % 5 == 0) {
      total += n; /* store the total as n plus itself */
    }
  }
  printf("%d\n", total); /* print total */
  return(0);
}
