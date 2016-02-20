#include <unistd.h>

/* include print_char function to print letters */
int print_char(char c)
{
  return (write(1, &c, 1)); /* write to output */
}

/* call char uppercase function */
char uppercase(char c)
{
  if (c > 96 && c < 123)
    {
      print_char(c - 32); /* print uppercase letter */
    }
  else
    {
      print_char(c); /* print character */
    }
  return (0);
}
