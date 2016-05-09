#include <stdlib.h>
#include "list.h"

char *str_copy(char *, int);
int add_node(List **list, char *str);

List *params_to_list(int ac, char **av)
{
  List *list;
  int i = 0;

  /* Create a pointer to the first item of the list. */
  list = NULL;

  /* For every command line argument, create a new list item. */
  for(; ac > 0; --ac) {
    if (add_node(&list, av[i]) == 1)
      return (NULL);
    ++i;
  }

  return(list);
}

int add_node(List **list, char *str)
{
  int len;
  List *tmp = *list;
  List *node = malloc(sizeof(List));
  if (node == NULL)
    return (1);
  for(len = 0; str[len] != '\0'; ++len);
  /* Copy the string parameter str into the node. */
  node->str = str_copy(str, len);
  /* The pointer next of the structure points to NULL so that it is last. */
  node->next = NULL;
  /* If the list is empty, create the first node. */
  if(*list == NULL) {
    *list = node;
  }
  /* If there are already nodes, then traverse until the last node. */
  else {
    while(tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = node;
  }
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
