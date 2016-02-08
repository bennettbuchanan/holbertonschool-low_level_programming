#include "my_functions.h"

/* call print_alphabet function */
void print_alphabet(void)
{
  /* define variables */
  char letter = 'a';
  int i;
  
  /* initiate a loop to print entire alphabet */
  for (i = 0; i < 26; i++)
    {
      print_char(letter);
      letter++;
    }
}
