#include "my_functions.h"

/* for number -2147483648, print minus sign and first digit */
void min()
{
   print_char('-');
   print_char('2');
}

/* call print_number function to print each digit using print_char */
void print_number(int n)
{
  int length = 0;
  int power = 1;
  int digit, length_stored, i;
  if (n == -2147483648)
    {n = 147483648;
      min();}
  if (n < 0 && n != -2147483648)/* print '-' and make n make positive*/
    {n *= -1;
     print_char('-');}
  if (n == 0)
    {print_char('0');}
  for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
    {length++;}
    length_stored = length;/* store value of length for later subtraction*/
  for (;length > 0; length--)/* subtract length by one for each iteration */
    {for (i = 1; length_stored > i; i++)
      {power *= 10;}
      digit = n / power; /* divide n by power to find the digit */
      print_char(digit + 48);
      n = n - (digit * power);
      power = 1;
      length_stored--;}
}
