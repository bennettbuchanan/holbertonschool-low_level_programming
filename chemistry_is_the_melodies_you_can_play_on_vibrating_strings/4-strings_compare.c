int strings_compare(char *s1, const char *s2)
{
  int i = 0;
  int j = 0;
  for ( ; s1[i] != '\0'; i++)
  {
  	if (s1[j] != s2[j]) /* if chars are different, break */
	{
	  break;
	}
	j++;
  }
  return(s1[j] - s2[j]); /* return difference in chars */
}
