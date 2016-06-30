#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "header.h"

int add_end_dl_list(List **, char *);
int add_begin_dl_list(List **, char *);
void print_dl_list(List *);

int main(void)
{
  List *list;
  list = NULL;
  if (add_begin_dl_list(&list, "Holberton") == 1)
    return (1);
  print_dl_list(list);
  free_dl_list(list);
  return (0);
}
