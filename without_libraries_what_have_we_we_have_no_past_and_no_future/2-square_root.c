int count_square(int n, int temp);

int square_root(int n) {
  int temp = n; /* store initial value for later testing */
  int root;
  root = count_square(n, temp);
  return root;
}

int count_square(int n, int temp)
{
  if (n * n == temp)
  {
    return n;
  }
  if (n < 1) {
    return -1;
  }
  n -= 1; /* decrement one for each time through */
  return count_square(n, temp);
}
