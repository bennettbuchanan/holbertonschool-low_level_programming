int print_char(char c);

int print_char(char c)
{
  return (write(1, &c, 1));
}