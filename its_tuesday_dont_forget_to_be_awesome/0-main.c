#include <limits.h>
int first_digit(int n);
int print_char(char c);

int main(void)
{
  print_char('0' + first_digit(1024));
  print_char('0' + first_digit(-3));
  print_char('0' + first_digit(3024));
  print_char('0' + first_digit(-7000000));
  print_char('0' + first_digit(0));
  print_char('0' + first_digit(INT_MAX));
  print_char('0' + first_digit(INT_MIN));
  return (0);
}
