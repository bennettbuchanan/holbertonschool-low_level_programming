#include <stdlib.h>

char *string_dup(char *str) {
  int i;
  char *s;

  /* Allocate space for longest possible string of ISO C90 compiler */
  s = malloc(sizeof(*s) * 509);

  if (s == NULL)
    {
      return (NULL);
    }

  /* Copy the string passed as a parameter */
  for (i = 0; str[i] != '\0'; i++) {
    s[i] = str[i];
  }

  return (s);
}
