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
      return (c - 32); /* print uppercase letter */
    }
  else
    {
      return (c); /* print character */
    }
}
