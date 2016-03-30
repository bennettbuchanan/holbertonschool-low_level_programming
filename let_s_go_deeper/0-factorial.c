int factorial(int n)
{
  if (n < 0 || n > 12)
  {
    return -1;
  }
  if (n <= 1)
  {
    return 1;
  }
  /* add n times n - 1 to the stack and then evaluate */
  return n * factorial(n - 1);
}
