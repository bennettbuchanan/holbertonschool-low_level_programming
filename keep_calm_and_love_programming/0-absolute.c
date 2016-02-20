/* call absolute function and test for the value of n */
int absolute(int n)
{
  if (n < 0)
    {
      return(n * -1);
    }
  if (n == 0)
    {
      return(0);
    }
  if (n > 0)
    {
      return (n);
    }
  return (0);
}
