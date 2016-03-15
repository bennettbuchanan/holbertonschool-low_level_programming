int print_char(char c);

void print_diagonal(int n)
{
  int line_num = 0;
  int temp;
  if (n > 0) /* print characters if n is greater than 0 */
  {
	for (; n > 0; n--) /* print pyramid n number of lines */
    {
      temp = line_num;
      for (; temp > 0; temp--) /* print line_num amount of spaces */
      {
      	print_char(' ');
      }
      line_num++;
      print_char('\\');
  	  print_char('\n');
    }
  } 
  else if (n <= 0)
  {
  	print_char('\n');
  }
}