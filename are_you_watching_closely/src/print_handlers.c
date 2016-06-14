#include "header.h"

/*
 * print_num() - Prints the number passed as parameter to stdout.
 * @arg1: The number to be printed.
 *
 * Return: Null.
 */
void print_num(int n)
{
        if (n >= 10)
                {
                        print_num(n / 10);
                }
        print_char(n % 10 + 48);
}

void print_neg_num(int n)
{
        if (n <= 10)
                {
                        print_num(n * 10);
                }
        print_char(n % 10 + 48);
}

/*
 * print_unsigned() - Prints the number passed as parameter to stdout.
 * @arg1: The number to be printed.
 *
 * Return: Null.
 */
void print_unsigned(unsigned int n)
{
        if (n >= 10)
                {
                        print_num(n / 10);
                }
        print_char(n % 10 + 48);
}

/*
 * get_unsigned_len() - Recursively divide a number by ten, adding one to i for
 each operation. Return the length of the number given.
 * @n: The number to find the length.
 * @i: The iteration starting point. This should be 0.
 *
 * Return: The lenth of the number passed.
 */
int get_unsigned_len(unsigned int n, int i)
{
        if (n >= 10)
                {
                        return get_num_len(n / 10, i + 1);
                }
        return i + 1;
}

/*
 * get_num_len() - Recursively divide a number by ten, adding one to i for each
 operation. Return the length of the number given.
 * @n: The number to find the length.
 * @i: The iteration starting point. This should be 0.
 *
 * Return: The lenth of the number passed.
 */
int get_num_len(int n, int i)
{
        if (n >= 10)
                {
                        return get_num_len(n / 10, i + 1);
                }
        return i + 1;
}

/* for number -2147483648, print minus sign and first digit */
void min()
{
   print_char('-'); /* print minus sign */
   print_char('2'); /* print digit '2' */
}

/* call print_number function to print each digit using print_char */
void print_number(int n)
{
  int length = 0;
  int power = 1;
  int digit, length_stored, i;
  if (n == -2147483648)
    {n = 147483648;
      min();} /* call min function */
  if (n < 0 && n != -2147483648)/* print '-' and make n make positive*/
    {n *= -1;
     print_char('-');} /* print minus sign */
  if (n == 0)
    {print_char('0');} /* print digit '0' */
  for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
    {length++;}
    length_stored = length;/* store value of length for later subtraction*/
  for (;length > 0; length--)/* subtract length by one for each iteration */
    {for (i = 1; length_stored > i; i++)
      {power *= 10;}
      digit = n / power; /* divide n by power to find the digit */
      print_char(digit + 48); /* print digit plus 48 on ascii */
      n = n - (digit * power);
      power = 1;
      length_stored--;}
}
