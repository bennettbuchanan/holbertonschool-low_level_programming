char *uppercase_string(char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++) { /* loop through string */
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 32; /* reassign lowercase to upcase */
    }
  }
  return (s);
}
