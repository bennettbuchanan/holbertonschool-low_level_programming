#include <stdio.h>
#include "str_struct.h"

struct String *string_to_struct(char *str);
void free_string_struct(struct String *str);

int main(void)
{
  struct String *str;

  str = string_to_struct("Holberton");
  free_string_struct(str);
  return (0);
}
