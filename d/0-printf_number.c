#include "my_functions.h"

/* call print_number function */
void printf_number(int n)
{
  int length = 0;
  int digit = 0;
  int sub = 0;
  int power = 1;
  int length_stored, i;

  /* if n is negative, make it a positive int and print a minus sign */
  if (n < 0)
    {
      n = 0 - n;
      print_char('-');
    }
  if (n == 0)
    {
      print_char('0');
    }
  /* find the decimal length of n */
  for (i = 1; n > i; i = i * 10)
    {
      length++;
    }
  /* store value of var length for later subtraction */
  length_stored = length;
      
  /* subtract length by 1 to iterate through each digit */
  for (;length > 0; length--)
    {
      /* find the power of length by multiplying 
       * itself length number of times
       */
      for (i = 1; length_stored > i; i++)
	{
	  power *= 10;
	}
	  
      /* divide n by power to find the digit */
      digit = n / power;
      print_char(digit + 48);

      /* find the amount to subtract by multiplying
       * the digit by the power
       */
      sub = digit * power;

      /* redefine variables and subtract length_stored by 1 */
      n = n - sub;
      power = 1;
      digit = 0;
      length_stored--;
   }
}
