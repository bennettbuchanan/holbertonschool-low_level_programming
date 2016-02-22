#include <unistd.h>

/* include print_char function to print letters */
int print_char(char c)
{
  return (write(1, &c, 1)); /* write to output */
}

/* call char lowercase function */
char lowercase(char c)
{
  if (c > 64 && c < 91)
    {
      return (c + 32); /* print uppercase letter */
    }
  else
    {
      return (c); /* print character */
    }
}
