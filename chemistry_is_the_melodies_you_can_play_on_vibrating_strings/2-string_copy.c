int find_len(const char *src);
int src_len = 0;

char *string_copy(char *dest, const char *src)
{
  int i;
  find_len(src);
  for (i = 0; i < src_len && src[i] != '\0'; i++)
      dest[i] = src[i];
  for ( ; i < src_len; i++)
      dest[i] = '\0';
  return dest;
}

int find_len(const char *src)
{
  while(src[src_len] != '\0') /* find length of string */
  {
    src_len++;
  } 
  return (0);
}
