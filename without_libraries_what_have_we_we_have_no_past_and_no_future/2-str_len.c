int str_len(char *str)
{
  int i;
  /* break out of loop when string reaches 0 in memory */
  for (i = 0; i >= 0; i++) {
    if (str[i] == 0) {     
      break;
    }
  }
  return (i);
}
