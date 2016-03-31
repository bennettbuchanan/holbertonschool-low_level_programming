char *nconcat_strings(char *dest, const char *src, int n)
{
  int i;
  int dest_len = 0;
  int src_len = 0;
  while(dest[dest_len] != '\0') /* find length of string */
  {
    dest_len++;
  }
  while(src[src_len] != '\0') /* find length of string */
  {
    src_len++;
  } 
  if (n > src_len)
  {
  	n = src_len;
  }
  for (i = 0; i < n; i++)
  {
  	dest[dest_len] = src[i];
  	dest_len++;
  }
  return dest; /* return pointer from function */
}