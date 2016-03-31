char *string_copy(char *dest, const char *src)
{
  int i;
  int src_len = 0;
  while(src[src_len] != '\0') /* find length of string */
  {
    src_len++;
  }
  for (i = 0; i < src_len && src[i] != '\0'; i++)
      dest[i] = src[i]; /* copy chars into new array */
  for ( ; i < src_len; i++)
      dest[i] = '\0'; /* declare end of array */
  return dest;
}
