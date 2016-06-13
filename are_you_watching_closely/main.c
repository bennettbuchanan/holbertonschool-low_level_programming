#include <limits.h>

int printf(const char *format, ...);

int main(void)
{
  int len;
  unsigned int ui;
  void *addr;

  len = printf("INTEGER{%d}, STRING{%s}\n", 98, "I am a string");
  ui = (unsigned int)INT_MAX + 1;
  addr = &len;
  printf("previous length{%d}\n", len);
  printf("UNSIGNED INTEGER{%u}\n", ui);
  printf("UNSIGNED INTEGER{%u}\n", INT_MIN);
  printf("ADDRESS{%p}\n", addr);
  printf("HEXADECIMAL{%X}\n", 94111);
  printf("UNKNOWN SPECIFIER{%Q}\n", len);
  return (0);
}
