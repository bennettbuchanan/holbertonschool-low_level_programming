#include <stdio.h>
int is_palindrome(char *s);

int main(void)
{
  int r;

  r = is_palindrome("level");
  printf("%d\n", r);
  r = is_palindrome("redder");
  printf("%d\n", r);
  r = is_palindrome("holberton");
  printf("%d\n", r);
  r = is_palindrome("step on no pets");
  printf("%d\n", r);
  return (0);
}
