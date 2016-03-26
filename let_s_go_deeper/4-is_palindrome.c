int str_length(char *str);
int helper(char *str_start, char *str_end, int i);

int is_palindrome(char *s)
{
  int length, leftofmiddle;
  length = str_length(s); /* find the length of the string */
  leftofmiddle = length / 2 - 1; /* find char that is left of middle */
  return helper(s, s + length - 1, leftofmiddle);
}

int str_length(char *str)
{
  if (*str == '\0')
  {
    return 0;
  }
  return 1 + str_length(str + 1); /* return length of string */
}

int helper(char *str_start, char *str_end, int i)
{
  if (i == 0)
  {
    return 1; /* if the string is a palindrome, return 1 */
  }
  if (*str_start != *str_end)
  {
    return 0; /* if the string is not a palindrome, return 0 */
  }
  return helper(str_start + 1, str_end - 1, i - 1); /* compare strings */
}
