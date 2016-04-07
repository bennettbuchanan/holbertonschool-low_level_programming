char *concat_strings(char *dest, const char *src)
{
  int i;
  int j = 0;
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
  for (i = src_len; i > 0; i--)
  {
  	dest[dest_len] = src[j];
  	j++;
  	dest_len++;
  }
  return dest; /* return pointer from function */
}
