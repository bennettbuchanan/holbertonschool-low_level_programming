int count_square(int n, int temp);

int is_prime_number(int n)
{
  return count_square(n, n); /* return result of count_square function. */
}

int count_square(int n, int temp)
{
  if (n * n == temp || n < 0)
  {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  n -= 1; /* decrement one for each time through */
  return count_square(n, temp);
}
