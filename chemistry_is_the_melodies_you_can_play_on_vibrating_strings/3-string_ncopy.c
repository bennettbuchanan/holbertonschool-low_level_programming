int find_len(const char *src);
char *string_ncopy(char *dest, const char *src, int n)
{
  int i = 0;  
  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = '\0';
  return dest;
}