char *rot13(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++)
  {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    {
      if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
      {
        s[i] = s[i] - 13; /* subtract 13 from char decimal place */
      }
      else if ((s[i] <= 'n' && s[i] >= 'a') || (s[i] <= 'N' && s[i] >= 'A'))
      {
        s[i] = s[i] + 13;  /* add 13 from char decimal place */
      }
    }
  }
  return (s);
}
