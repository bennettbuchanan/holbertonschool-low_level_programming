int print_char(char c);

void print_line(int n)
{
  if (n > 0) /* print underscore only if n is greater than 0 */
  {
	for (; n > 0; n--) /* print underscore n number of times */
    {
  	  print_char('_');
    }
  }
  print_char('\n');
}