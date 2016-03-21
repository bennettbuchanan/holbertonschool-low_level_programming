#include <stdio.h>
char *rot13(char *);

int main(void)
{
  char s[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13) is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is a special case of the Caesar cipher, developed in ancient Rome.\n\nBecause there are 26 letters (2×13) in the basic Latin alphabet, ROT13 is its own inverse; that is, to undo ROT13, the same algorithm is applied, so the same action can be used for encoding and decoding.\n";
  char *p;

  p = rot13(s);
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  printf("------------------------------------\n");
  p = rot13(s);
  printf("------------------------------------\n");
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  p = rot13(s);
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  printf("------------------------------------\n");
  return (0);
}
