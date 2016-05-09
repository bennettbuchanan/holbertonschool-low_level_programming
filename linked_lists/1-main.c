#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List *params_to_list(int ac, char **av);

void print_list(List *head)
{
  List *current = head;
  while (current != NULL) {
    printf("%s\n", current->str);
    current = current->next;
  }
}

int main(int ac, char **av)
{
  List *params_list;

  params_list = params_to_list(ac, av);
  if (params_list == NULL)
    return (1);
  print_list(params_list);
  return (0);
}
