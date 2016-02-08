#include "my_functions.h"

/* call print_tebahpla function */
void print_tebahpla(void)
{
  /* define variables */
  int letter = 'z';
  int i;
  
  /* initiate a loop to print entire alphabet backwards */
  for (i = 0; i < 26; i++)
    {
      /* call print_char function with variable as argument */
      print_char(letter);
      letter--;
    }
}
