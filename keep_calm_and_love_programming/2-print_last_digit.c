#include "my_functions.h"

/* call print_number function to print each digit using print_char */
void print_last_digit(int n)
{
  int length = 0;
  int power = 1;
  int digit, length_stored, i;
  if (n == -2147483648)
    {
      n = 147483648;
    }
  
  if (n < 0 && n != -2147483648)/* print '-' and make n make positive*/
    {
      n *= -1;
    } /* print minus sign */
  if (n == 0)
    {print_char('0');} /* print digit '0' */
  for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
    {
      length++;
    }
  length_stored = length; /* store value of length for later subtraction*/
  for (;length > 0; length--) /* subtract length by one for each iteration */
    {
      for (i = 1; length_stored > i; i++)
	{
	  power *= 10;
	}
      digit = n / power; /* divide n by power to find the digit */
      if (length == 1)
	{
	  print_char(digit + 48); /* print digit plus 48 on ascii */
	}
      n = n - (digit * power);
      power = 1;
      length_stored--;
    }
}
