#include <stdio.h>
#include <stdlib.h>
char *string_nconcat(char *, char *, int);

int main()
{
  char *concat;

  concat = string_nconcat("Holberton ", "School dfdfsdf!!!", 5);
  printf("%s\n", concat);
  free(concat);
  return (0);
}
