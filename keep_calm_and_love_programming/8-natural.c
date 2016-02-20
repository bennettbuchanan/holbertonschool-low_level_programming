#include <stdio.h>

int main(void) {
  int n = 1024;
  int total = 0;
  
  for (total = 0; n > 0; n--) {
    if (n % 5 == 0 && n % 3 != 0) {
      total += n;
    }
    if (n % 3 == 0 && n % 5 != 0) {
      total += n;
    }
    if (n % 3 == 0 && n % 5 == 0) {
      total += n;
    }
  }
      printf("%d\n", total);
  
  return(0);
}
