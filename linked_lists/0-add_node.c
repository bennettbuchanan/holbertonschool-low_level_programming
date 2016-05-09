#include <stdlib.h>
#include "list.h"

char *str_copy(char *, int);

int add_node(List **list, char *str)
{
  List *node;
  int len;

  /* Allocate memory for the new node. */
  node = malloc(sizeof(List));
  if (node == NULL)
    return (1);

  /* Find the length of the string. */
  for(len = 0; str[len] != '\0'; ++len);

  /* Copy the string parameter str into the node. */
  node->str = str_copy(str, len);

  /* The pointer next of the structure points to NULL. */
  node->next = *list;

  /* The original pointer to NULL points to the newly allocated struct. */
  *list = node;

  return (0);
}

char *str_copy(char *src, int len)
{
  int i;
  char *dest;

  /* Allocate the same amount of memory as the original string. */
  dest = malloc(sizeof(char) * (len + 1));
  if (dest == NULL)
    return (NULL);

  /* Copy the string. */
  for(i = 0; i < len + 1; ++i){
    dest[i] = src[i];
  }

  return(dest);
}
