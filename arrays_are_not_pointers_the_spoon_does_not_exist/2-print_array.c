int print_char(char c);
void min();
void print_num(int n);
void neg_zero(int n);

void min()
{
   print_char('-'); /* print minus sign */
   print_char('2'); /* print digit '2' */
}

void print_array(int *a, int n) 
{
	int i;
	int number;

	for (i = 0; i < n; i++)
	{
		number = a[i];
		neg_zero(number); /* print out the number */
		if(i != n - 1)
		{
			print_char(',');
			print_char(' ');
		}
		else
		{
			print_char('\n');
		}
	}
}

void neg_zero(int n)
{	
  	if (n == -2147483648)
    	{
    		n = 147483648;
      		min();
      	} /* call min function */
  	if (n < 0 && n != -2147483648)/* print '-' and make n make positive*/
	    {
	    	n *= -1;
	     	print_char('-');
	    } /* print minus sign */
    if (n == 0)
    	{
	    	print_char('0');
	    } /* print digit '0' */
	print_num(n);
}

void print_num(int n)
{
	int length = 0;
  	int power = 1;
  	int digit, length_stored, i;
	for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
	    {
	    	length++;
	    }
    length_stored = length;/* store value of length for later subtraction*/
    for (;length > 0; length--)/* subtract length by one for each iteration */
	    {
	    	for (i = 1; length_stored > i; i++)
	      	{
	      		power *= 10;
	      	}
	        digit = n / power; /* divide n by power to find the digit */
	        print_char(digit + 48); /* print digit plus 48 on ascii */
	        n = n - (digit * power);
	        power = 1;
	        length_stored--;
	    }
}
