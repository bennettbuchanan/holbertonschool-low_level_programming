#include <stdio.h>

int main(int argc, char **argv) {
  int i;
  /* For each argument given to program, print to output */
  for (i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
	return (0);
}
