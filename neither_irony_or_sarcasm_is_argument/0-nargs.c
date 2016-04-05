#include <stdio.h>

int main(int argc, char **argv) {
  int num_args;
  **argv = **argv;
  num_args = argc - 1;
  /* print number of arguments given to program */
  printf("%d\n", num_args);
  return (0);
}
