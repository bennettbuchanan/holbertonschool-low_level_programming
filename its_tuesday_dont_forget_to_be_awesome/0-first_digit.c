/* call first_digit function to return the first digit of a number */
int first_digit(int n)
{
  int length = 0;
  int power = 1;
  int digit, length_stored, i;
  if (n == -2147483648 || n == 2147483647)
    {n = 2;}
  if (n < 0 && n != -2147483648)/* make n positive*/
    {n *= -1;}
  for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
    {length++;}
  length_stored = length;/* store value of length for later subtraction*/
  for (;length > 0; length--)/* subtract length by one for each iteration */
    {for (i = 1; length_stored > i; i++)
	{power *= 10;}
      digit = n / power; /* divide n by power to find the digit */
      return(digit); /* return the digit for main function */
      n = n - (digit * power);
      power = 1;
      length_stored--;}
}
