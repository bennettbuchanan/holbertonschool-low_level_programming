#include <stdio.h>

void print_to_98(int n)
{
  if (n == 98) {
    printf("%d\n", n);
  }
  if (n < 98) {
    for (; n < 98; n++) {
      printf("%d, ", n);
    }
    printf("98\n");
  }
  if (n > 99) {
    for (; n > 98; n--) {
      printf("%d, ", n);
    }
    printf("98\n");
  }
}
