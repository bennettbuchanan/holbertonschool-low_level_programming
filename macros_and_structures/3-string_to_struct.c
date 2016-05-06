#include <stdlib.h>
#include "str_struct.h"

int find_len(char *);
char *str_copy(char*, int);

struct String *string_to_struct(char *str)
{
  int length;
  struct String *string;
  char *cp;

  /* Find the length of the string. */
  length = find_len(str);

  /* Allocate the memory that is the same size as the struct. */
  string = malloc(sizeof(struct String));

  /* Handle a failed memory allocation. */
  if (string == NULL)
    return (NULL);

  /* Make a copy of the original string. */
  cp = str_copy(str, length);

  /* Assign the given values to the string struct. */
  string->str = cp;
  string->length = length;

  return(string);
}

char *str_copy(char *src, int length)
{
  int i;
  char *dest;

  /* Allocate the same amount of memory as the original string. */
  dest = malloc(sizeof(char) * (length + 1));

  /* Handle a failed memory allocation. */
  if (dest == NULL)
    return (NULL);

  /* Copy the string. */
  for(i = 0; i < length; ++i){
    dest[i] = src[i];
  }

  return(dest);
}

int find_len(char *str)
{
  int i = 0;

  /* Increment through the string until NULL terminator. */
  while (str[i] != '\0') {
    ++i;
  }

  /* Var i is now the length of the string passed. */
  return (i);
}
