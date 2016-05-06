#include "str_struct.h"
#include <unistd.h>
#include <stdlib.h>

int print_char(char c);

void print_string_struct(struct String *str)
{
  int i = 0;

  /* Increment through the value and print each char. */
  while (str->str[i] != '\0') {
    print_char(str->str[i]);
    ++i;
  }

  /* Then print the remaining characters... */
  print_char(',');
  print_char(' ');

  /* Add 48 to print the ascii value of the length. */
  print_char(str->length + 48);
  print_char('\n');

  /* Free the space in memory allocated for the struct. */
  free(str);

}
