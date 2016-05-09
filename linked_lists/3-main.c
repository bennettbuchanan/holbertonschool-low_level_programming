#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);
void print_list(List *list);

int main(void)
{
  List *list;

  list = NULL;

  print_list(list);
  if (add_node(&list, "Holberton") == 1)
    return (1);
    print_list(list);
  if (add_node(&list, "School") == 1)
    return (1);
    print_list(list);
  if (add_node(&list, "is Cool") == 1)
    return (1);
  print_list(list);
  return (0);
}
