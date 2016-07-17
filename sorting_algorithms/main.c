#include <stdlib.h>

void sort_str_array(char **);
void print_array_str(char **);

int main(void)
{
  char *array[] = {"ad", "aa", "ac", NULL};

  print_array_str(array);
  sort_str_array(array);
  print_array_str(array);
  return (0);
}
