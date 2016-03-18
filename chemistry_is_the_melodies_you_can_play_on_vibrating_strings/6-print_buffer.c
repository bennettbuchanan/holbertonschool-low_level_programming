int print_char(char c);
int print_place(int size);

void print_buffer(char *b, int size)
{
  fflush(stdout);
  printf("%s\n", b);
  print_place(size);
}

int print_place(int size)
{
  int i;
  int row_num = size / 10;
  if (size %10 != 0)
  {
  	row_num += 1;
  }

  for (i = 0; i < row_num; i++)
  {
  	print_char('x');
  	print_char('\n');
  }
  return (0);
}
