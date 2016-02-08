#include "my_functions.h"

/* call print_alphabet function */
void print_base16(void)
{
  /* define variables */
  int letter = 48;
  int i;
  
  /* initiate a loop to print entire alphabet */
  for (i = 0; i < 10; i++)
    {
      print_char(letter);
      letter++;
    }
  
  letter = 65;
  
  for (i = 0; i < 6; i++)
    {
      print_char(letter);
      letter++;
    }
}
