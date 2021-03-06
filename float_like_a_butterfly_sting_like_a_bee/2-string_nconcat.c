#include <stdlib.h>

int find_len(char *);

char *string_nconcat(char *s1, char *s2, int n) {
  int i, str_end;
  int j = 0;
  char *concat;
  str_end = find_len(s1);

  /* Allocate space for two longest possible strings of ISO C90 compiler */
  concat = malloc(sizeof(char) * 1024);
  if (concat == NULL)
    {
      return (NULL);
    }
  /* Copy the string passed as a parameter */
  for (i = 0; s1[i] != '\0'; i++) {
    concat[i] = s1[i];
  }
  /* Copy the string passed as a parameter */
  for (i = str_end; j != n; i++) {
    concat[i] = s2[j];
    j++;
  }
  concat[i] = '\0';
  return (concat);
}


int find_len(char *str) {
  int i = 0;

  /* Find the length of a string */
  while (str[i] != '\0') {
    i++;
  }
  return i;
}
