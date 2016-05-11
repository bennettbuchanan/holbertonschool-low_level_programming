#include <unistd.h>
int print_char(char c);

void print_num(int n)
{
  if (n >= 10)
  {
    print_num(n / 10);
  }
  print_char(n % 10 + 48);
}

int main(void)
{
  print_num(30);
  return (0);
}
