#include <unistd.h>

/*
 * print_char() - Print a single character to stdout.
 * @arg1:
 *
 * Return:
 */
int print_char(char c)
{
  return (write(1, &c, 1));
}
