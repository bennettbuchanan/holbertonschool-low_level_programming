#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int add_node(List **list, char *str);
int list_size(List *list);

int main(void)
{
  List *list;
  int size;

  list = NULL;
  size = list_size(list);
  printf("List size: %d\n", size);
  if (add_node(&list, "Holberton") == 1)
    return (1);
  size = list_size(list);
  printf("List size: %d\n", size);
  if (add_node(&list, "School") == 1)
    return (1);
  size = list_size(list);
  printf("List size: %d\n", size);
  return (0);
}
