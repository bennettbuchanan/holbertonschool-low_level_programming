#include <stdio.h>
/* call print_to_98 and store input as n */
void print_to_98(int n)
{
  if (n == 98) {
    printf("%d\n", n); /* print 98 */
  }
  if (n < 98) {
    for (; n < 98; n++) {
      printf("%d, ", n); /* print n, incrementing up by one */
    }
    printf("98\n"); /* at 98, print newline instead of comma and space */
  }
  if (n > 99) {
    for (; n > 98; n--) {
      printf("%d, ", n); /* print n, incrementing down by one */
    }
    printf("98\n"); /* at 98, print newline instead of comma and space */
  }
}
