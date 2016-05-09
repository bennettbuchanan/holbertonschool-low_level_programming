#include <stdlib.h>
#include "list.h"
#include "limits.h"

int add_node(List **list, char *str);
int insert_in_list(List **list, char *content, int index);
void print_list(List *list);

int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "Holberton") == 1)
    return (1);
  print_list(list);
  if (add_node(&list, "CA 94111") == 1)
    return (1);

  print_list(list);
  return (0);
}
