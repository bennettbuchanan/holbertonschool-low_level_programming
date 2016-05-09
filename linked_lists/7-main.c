#include <stdlib.h>
#include "list.h"
#include "limits.h"

int add_node(List **list, char *str);
void remove_from_list(List **list, int index);
void print_list(List *list);
void free_list(List *list);

int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "zero") == 1)
    return (1);
  if (add_node(&list, "one") == 1)
    return (1);
  if (add_node(&list, "two") == 1)
    return (1);
  if (add_node(&list, "three") == 1)
    return (1);
  if (add_node(&list, "four") == 1)
    return (1);
  if (add_node(&list, "five") == 1)
    return (1);
  print_list(list);
  remove_from_list(&list, 234);
  print_list(list);
  free_list(list);
  return (0);
}
