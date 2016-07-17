#include <stdlib.h>
#include "list.h"

void sort_list(List **, int (*)(List *, List *));
int node_cmp(List *, List *);
List *array_to_list(char **);
void print_list(List *);
void free_list(List *);

int main(void)
{
  List *list;
  char *array[] = {"San Marcos", "Holberton", "School", "California", "San Francisco", NULL};

  if (!(list = array_to_list(array)))
    return (1);
  print_list(list);
  sort_list(&list, &node_cmp);
  print_list(list);
  free_list(list);
  return (0);
}
