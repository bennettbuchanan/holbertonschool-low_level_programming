void reverse_string(char *s)
{
  int i, j, k;
  
  /* find the length of the string */
  for (i = 0; i >= 0; i++) {
    if (s[i] == 0) {     
      break;
    }
  }
  /* subtract 1 from i */
  i -= 1;
  for(j = 0; j < i; j++){
    /* store last array item in k */
    k = s[i];
    s[i] = s[j];
    /* assign first array item as k */
    s[j] = k;
    /* subtract one to cycle through array */
    i--;
  }
}
