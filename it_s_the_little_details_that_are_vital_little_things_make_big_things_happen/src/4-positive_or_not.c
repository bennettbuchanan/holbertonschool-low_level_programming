int print_char(char c);

/* call positive_or_not function */
void positive_or_not(int n)
{
  char P = 'P';
  char N = 'N';
  char Z = 'Z';
  /* create conditional statements to print P, N, or Z */
  if (n > 0)
    {
      /* call print_char function with variable as argument */
      print_char(P);
    }
  if (n < 0)
    {
      /* call print_char function with variable as argument */
      print_char(N);
    }
  if (n == 0)
    {
      /* call print_char function with variable as argument */
      print_char(Z);
    }
}
