#include "header.h"

/*
 * print_char() - Prints a char to stdout.
 * @c: The char to be printed.
 *
 * Return: The return value of the write function.
 */
int print_char(char c)
{
      return (write(1, &c, 1));
}
