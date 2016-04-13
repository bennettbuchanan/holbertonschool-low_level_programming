#include <stdio.h>
#include <stdlib.h>
char *string_concat(char *, char *);

int main()
{
  char *concat;

  concat = string_concat("HolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolbertonHolber ", "School");
  printf("%s\n", concat);
  free(concat);
  return (0);
}
