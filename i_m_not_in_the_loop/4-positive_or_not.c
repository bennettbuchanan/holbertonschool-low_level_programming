#include "my_functions.h"
/* call positive_or_not function */
void positive_or_not(int n)
{
  /* define variables */
  char P = 'P';
  char N = 'N';
  char Z = 'Z';
  /* create conditional statements to print P, N, or Z */
  if (n > 0)
    {
      print_char(P);
    }
  
  if (n < 0)
    {
      print_char(N);
    }
  
  if (n == 0)
    {
      print_char(Z);
    }  
}
