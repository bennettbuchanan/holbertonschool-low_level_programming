int power(int x, int y)
{
  if (y < 0)
  {
    return -1;
  }
  if (y == 0)
  {
    return 1;
  }
  if (y == 1)
  {
    return x;
  }
  y -= 1;
  return x * power(x, y); /* recursively call the function */
}
