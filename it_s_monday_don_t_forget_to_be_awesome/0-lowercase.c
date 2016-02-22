/* call char lowercase function */
char lowercase(char c)
{
  if (c > 64 && c < 91) /* if the character is uppercase */
    {
      return (c + 32); /* print lowercase letter */
    }
  else
    {
      return (c); /* print character */
    }
}
