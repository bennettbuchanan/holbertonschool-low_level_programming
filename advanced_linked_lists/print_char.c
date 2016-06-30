#include <unistd.h>

/*
 * print_char() - Print a single character to stdout.
 * @c: The character to be printed.
 *
 * Return: The return value of the write function.
 */
int print_char(char c)
{
  return (write(1, &c, 1));
}
